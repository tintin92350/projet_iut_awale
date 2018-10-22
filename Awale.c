//
// Awale.c
// Définit toute les fonctions du jeux
#include "Awale.h"

// Fichiers du jeu
#include "AwaleConstant.h"
#include "IOExtends.h"
#include "Plateau.h"

/*******************************************************************************
 * FONCTIONS D'AFFICHAGE DES INFORMATIONS
 ******************************************************************************/

/**
 * Afficher le score des joueurs
 * @param unsigned int[2], Les scores des joueurs
 */
void afficher_scores(const unsigned int scores[2])
{
    // Chaine de caractere des scores
    char score_j1[25];
    char score_j2[25];

    // Imprime les scores dans les chaines de caractères
    sprintf(score_j1, "JOUEUR 1 : %d", scores[0]);
    sprintf(score_j2, "JOUEUR 2 : %d", scores[1]);

    // On affiche les informations sur la partie en cour
    affichage_droite_gauche(score_j1, score_j2);

    // On affiche une séparation
    affiche_separation_horizontal();
}

/*******************************************************************************
 * FONCTIONS DU JEU
 ******************************************************************************/

/**
 * Demande à l'utilisateur un emplacement
 * @param AwalePartie, la partie en cours
 * @return Emplacement, retourne l'emplacement demandé
 */
Emplacement demande_emplacement_au_joueur(AwalePartie * partie)
{
    // L'emplacement souhaité
    // en caractère
    char emplacement_demande[10];

    // On demande de l'entrée
    // tant qu'elle n'est pas valide !
    do {
        printf("%sJoueur %d%s$ ", partie->joueur == 0 ? RED : GRN, partie->joueur + 1, RESET);
        scanf(" %s", emplacement_demande);
    }
    while(!entree_respecte_regles(emplacement_demande[0], partie->joueur, partie->plateau, partie->famines[joueur_suivant(partie->joueur)], partie));

    // On convertit la coordonnée x de l'emplacement demandé
    int cx = conversion_char_vers_coordonnee_x(emplacement_demande[0]);

    // On renvoi l'emplacement
    return emplacement_defaut(cx, partie->joueur);
}

/**
 * Fonction qui permet de jouer un coup selon l'emplacement
 * @param Plateau - 2Dimensions, Le plateau de jeu
 * @param Emplacement, L'emplacement où prendre les graines
 */
Emplacement jouer_coup(int plateau[2][6], const Emplacement empGraines)
{
    // Emplacement où déposer les graines
    Emplacement emp = empGraines;

    // On récupère le nombre de graine à prendre
    int nbr_graine = recupere_nombre_graine(plateau, empGraines);

    // On effectue la saisi et le dépot de graine
    // pour chaque graine dans la case choisi
    while((nbr_graine--) > 0)
    {
        // On séléctionne l'emplacement suivant
        emp = emplacement_suivant(emp);
        
        // On vérifie que les emplacements ne sont pas les même
        // si c'est le cas on passe à la case suivante
        if(emplacement_sont_les_memes(emp, empGraines))
            emp = emplacement_suivant(emp);

        // On ajoute puis on retire
        ajouter_graine(plateau, emp, 1);
        enlever_graine(plateau, empGraines, 1);
    }

    // On renvoi le dernier emplacement
    return emp;
}

/**
 * Fonction qui ramasse si possible les graines
 * @param Plateau - 2Dimensions, Le plateau de jeu
 * @param Emplacement, L'emplacement où prendre les graines
 * @param unsigned int, Le joueur qui vient de jouer
 * @return unsigned int, Le nombre de graine obtenue
 */
unsigned int ramasser_graines(int plateau[2][6], Emplacement empGraines, const unsigned int joueur)
{
    // Nombre de graine prise
    unsigned int nbr_graine_prise = 0;

    // On sait qu'on a au moin une possiblité
    while(emplacement_est_ramassable(plateau, empGraines, joueur))
        {
            printf("peut rammasser\n");
            // On recupere combient il y a de graine a prendre
            unsigned int nbr_graine = recupere_nombre_graine(plateau, empGraines);
            
            // On enlève ce nombre à l'emplacement (on met à 0)
            enlever_graine(plateau, empGraines, nbr_graine);

            // On ajoute se nombre au nombre total
            nbr_graine_prise += nbr_graine;

            // On passe à la case précedente
            empGraines = emplacement_precedent(empGraines);
        }

    // On retourne le nombre de graine obtenue
    return nbr_graine_prise;
}

/**
 * Fonction qui renvoi le joueur suivant
 * @param unsigned int, Joueur actuel
 * @return unsigned int, Joueur suivant
 */
unsigned int joueur_suivant(const unsigned int joueur)
{
    return (joueur + 1) % 2;
}

/*******************************************************************************
 * FONCTIONS DE CONVERSION
 ******************************************************************************/

/**
 * Fonction qui convertit un caractère en sa coordonnée x dans le plateau
 * @param char, Le caractère à convertir
 * @return int, Renvoie la coordonnée ou -1 (erreur)
 */
int conversion_char_vers_coordonnee_x(const char entree)
{
    // On convertit si l'entrée correspond au joueur 1
    if(entree >= 'a' && entree <= 'f')
        return (int)(entree - 'a');
    // On convertit si l'entrée correspond au joueur 2
    else if(entree >= 'A' && entree <= 'F')
        return (int)(entree - 'A');

    // Erreur le format de l'entree n'est pas standard
    return -1; 
}

/*******************************************************************************
 * FONCTIONS DE VERIFICATION
 ******************************************************************************/

/**
 * Vérifie si l'entrée utilisateur est standard
 * @param char, l'entrée utilisateur
 * @return BOOL
 */
BOOL entree_utilisateur_est_standard(const char entree)
{
    return conversion_char_vers_coordonnee_x(entree) >= 0;
}

/**
 * Vérifie si la case entrée par l'utilisateur lui appartient
 * @param char, Entrée à tester
 * @param unsigned int, Utilisateur en question
 * @return BOOL
 */
BOOL entree_appartient_a_utilisateur(const char entree, const unsigned int joueur)
{
    // On vérifie qu'il sagit bien de la case de l'utilisateur
    if((joueur == JOUEUR_1 && (entree >= 'a' && entree <= 'f')) || (joueur == JOUEUR_2 && (entree >= 'A' && entree <= 'F')))
        return TRUE;

    // Sinon on renvoi faux !
    return FALSE;
}

/**
 * Vérifie si la case entrée par l'utilisateur respecte toute les règles
 * pour continuer
 * @param char, Entrée à tester
 * @param unsigned int, Utilisateur en question
 * @param Plateau - 2Dimensions, Le plateau de jeu
 * @param BOOL, Le joueur suivant est-il en famine ?
 * @param AwalePartie, Partie en cours
 * @return BOOL
 */
BOOL entree_respecte_regles(const char entree, const unsigned int joueur, const int plateau[2][6], const BOOL joueur_suivant_famine, AwalePartie * partie)
{
    // 1. L'entrée doit être conforme, c'est-à-dire comprise entre "a" et "f"
    // et "A" et "F"
    if(!entree_utilisateur_est_standard(entree))
        {
            if(entree == 's')
                if(enregistrer_partie("save", partie))
                    printf("La partie à été sauvegardée !\n");

            printf("Attention l'entree n'est pas standard !\n");
            return FALSE;
        }

    // 2.0 La case demandé doit appartenir au joueur qui la demande
    if(!entree_appartient_a_utilisateur(entree, joueur))
        {
            printf("Attention cet emplacement ne vous appartient pas !\n");
            return FALSE;
        }

    // On convertit l'entree utilisateur en entier
    unsigned int entree_id = conversion_char_vers_coordonnee_x(entree);

    // 3.0 La case demandé ne doit pas etre vide
    if(plateau[joueur][entree_id] == 0)
        {
            printf("Attention cet emplacement est vide !\n");
            return FALSE;
        }

    // Si l'adversaire est en famine
    if(joueur_suivant_famine)
    {
        Emplacement emp = emplacement_defaut(entree_id, joueur);
        // 4.0 La case demandé doit nourrire l'adversaire
        if(joueur_peut_jouer_cette_case_famine(plateau, joueur, emp))
            {
                printf("Attention cet emplacement ne peut nourrire l'adversaire !\n");
                return FALSE; 
            }
    }

    // Sinon elle respecte toute les règfes
    return TRUE;
}


/**
 * Vérifie si l'emplacement est propice à un ramassage
 * @param Plateau - 2Dimensions, Le plateau de jeu
 * @param Emplacement, L'emplacement à vérifier
 * @param unsigned int, Le joueur qui vient de jouer
 * @return BOOL
 */
BOOL emplacement_est_ramassable(const int plateau[2][6], const Emplacement emp, const unsigned int joueur)
{
    return emp.y != joueur && (plateau[emp.y][emp.x] == 2 || plateau[emp.y][emp.x] == 3);
}


/**
 * Vérifie si le joueur j est en famine
 * @param Plateau - 2Dimensions, Le plateau de jeu
 * @param unsigned int, Le joueur qui vient de jouer 
 */
BOOL joueur_en_famine(const int plateau[2][6], const unsigned int joueur)
{
    return plateau_ligne_est_vide(plateau, joueur);
}


/**
 * Vérifie si un joueur peut nourrie son adversaire
 * @param Plateau - 2Dimensions, Le plateau de jeu
 * @param unsigned int, Le joueur qui vient de jouer 
 * @return BOOL
 */
BOOL joueur_peut_nourrire(const int plateau[2][6], const unsigned int joueur)
{
    if(joueur == JOUEUR_1)
    {
        for(unsigned int i = 0; i < 6; i++)
            if(i - plateau[joueur][i] < 0)
                return TRUE;
    }
    else if(joueur == JOUEUR_2)
    {
        for(unsigned int i = 0; i < 6; i++)
            if(i + plateau[joueur][i] > 5)
                return TRUE;
    }

    return FALSE;
}

/**
 * Vérifie en cas de famine si le joueur peut jouer cette case
 * @param Plateau - 2Dimensions, Le plateau de jeu
 * @param unsigned int, Le joueur qui vient de jouer 
 * @param Emplacement, l'emplacement à tester
 */
BOOL joueur_peut_jouer_cette_case_famine(const int plateau[2][6], const unsigned int joueur, const Emplacement emp)
{
    if(joueur == JOUEUR_1 && emp.x - plateau[joueur][emp.x] < 0)
            return TRUE;
    else if(joueur == JOUEUR_2 && emp.x + plateau[joueur][emp.x] > 5)
            return TRUE;

    return FALSE;
}