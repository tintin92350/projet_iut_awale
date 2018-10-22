//
// Main.c
// Fichier principale du programme
// concentrent les diffèrenes fonctins et contenue
// du jeu pour son fonctionnement logique

// En-tête obligatoires
#include "main.h"

// Fichiers du jeu
#include "Awale.h"
#include "Plateau.h"
#include "AwalePartie.h"
#include "Emplacement.h"
#include "IOExtends.h"

/**
 * Introduction du jeu
 */
void introduire_le_jeu();

// Entree principale du programme
int main(void)
{
    // Initialisation des informations sur la console
    // nécessaire au bon fonctionnement des fonctions
    // d'entrée / sortie étendu
    initialise_informations_console();

    // Introduction du jeu
    introduire_le_jeu();

    // Créer une partie
    AwalePartie awale;
    
    // On vérifie si une partie existe deja
    if(fichier_exist("save"))
        {
            printf("Une partie à été sauvegardé, voulez-vous l'ouvrir ? [o/n]\n");
            char choix;
            scanf(" %c", &choix);

            if(choix== 'o')
                {
                    if(recuperer_partie("save", &awale))
                        remove("save");
                }
            else
                awale = creer_partie();
        }
    else awale = creer_partie();

    // Tant que le jeu est en cour d'execution
    // on continue de jouer :)
    while(est_en_execution(awale))
        {
            // On teste si le joueur (en cour) est en famine
            // si c'est le cas il a perdu
            if(awale.famines[awale.joueur])
                {
                    enregistre_score("HallOfFame.txt", awale.joueur + 1, awale.scores[awale.joueur]);
                    printf("Le joueur %d à gagné !", joueur_suivant(awale.joueur) + 1);
                    quitter_partie(&awale);
                }

            // Initialisation des informations sur la console
            // nécessaire au bon fonctionnement des fonctions
            // d'entrée / sortie étendu (encore une fois en cas
            // de changement de la taille de la fenêtre)
            initialise_informations_console();

            // On efface l'écran
            effacer_console();

            // On affiche les scores des joueurs
            afficher_scores(awale.scores);

            // On affiche la plateau de facon centré
            afficher_plateau(awale.plateau);

            // Demande au joueur la case qu'il souhaite jouée
            affiche_separation_horizontal();
            afficher_dernier_coup_joue(awale);
            printf("Quel emplacement souhaitez-vous jouer ?\n");
            
            // On test si l'adversaire est en famine
            // si c'est le case on test si on peut le nourrire
            // si ce n'est pas possible il a gagné
            if(awale.famines[joueur_suivant(awale.joueur)])
                if(!joueur_peut_nourrire(awale.plateau, awale.joueur))
                    {
                        enregistre_score("HallOfFame.txt", awale.joueur + 1, awale.scores[awale.joueur]);
                        printf("Le joueur %d à gagné !", awale.joueur + 1);
                        quitter_partie(&awale);
                    }

            // On récupère l'emplacement demandé par le joueur
            awale.emplacement = demande_emplacement_au_joueur(&awale);

            // Met à jour le dernier coup joué
            awale.dernier_emplacement = awale.emplacement;

            // On jou le coup demandé puis on récupère la
            // dernière case du coup
            awale.emplacement = jouer_coup(awale.plateau, awale.emplacement);

            // On teste si le joueur (en cours) est en famine
            // si c'est le cas on l'indique
            awale.famines[awale.joueur] = joueur_en_famine(awale.plateau, awale.joueur);

            // On vérifie si on peut ramasser
            // si c'est le cas on ramasse ainsi de suite
            // et on récupère le score du joueur
            awale.scores[awale.joueur] = ramasser_graines(awale.plateau, awale.emplacement, awale.joueur);

            // On teste si le joueur (suivant) est en famine
            // si c'est le cas on l'indique
            awale.famines[awale.joueur] = joueur_en_famine(awale.plateau, joueur_suivant(awale.joueur));

            // On teste si le joueur a gagner
            if(awale.scores[awale.joueur] > 24)
                {
                    enregistre_score("HallOfFame.txt", awale.joueur + 1, awale.scores[awale.joueur]);
                    printf("Le joueur %d à gagné !", awale.joueur + 1);
                    quitter_partie(&awale);
                }

            // On passe au joueur suivant
            awale.joueur = joueur_suivant(awale.joueur);

            // Met le premier coup à false
            if(awale.premier_coup)
                awale.premier_coup = FALSE;
        }

    // Retourne un code
    // d'erreur succés (aucune erreur)
    return EXIT_SUCCESS;
}

/**
 * Introduction du jeu
 */
void introduire_le_jeu()
{  
    // Légendes à afficher
    const char * legendes_text[7] = {
        "Ils ont marché longtemps, très longtemps à travers le désert...",
        "jusqu'à ce qu'ils arrivent au bord de la mer...",
        "Ils ont fait des provisions de coquillages..",
        "puis sont repartis dans leur village",
        "En chemin, ils ont fait des trous dans le sable",
        "pour stocker les coquillages.",
        "C'est ainsi qu'est né le jeu : des coquillages dans des trous"
    };

    // On afficher au centre chaque légende
    for(unsigned int legende = 0;legende < 7; legende++)
    {
        // On affiche sa valeur au entre de la console
        affichage_centre((char*)legendes_text[legende]);
        
        // Puis on attend 1s
        #ifndef DEBUG
        sleep(1);
        #else
        sleep(0);
        #endif
    }

    // Retour à la ligne
    printf("\n");

    // On affiche 3 tirets
    // avec une animation
    for(unsigned int compteur = 0; compteur < 3; compteur++)
    {
        // On affiche le tiret
        affichage_centre("-");
        // Attend 1 second
        #ifndef DEBUG
        sleep(1);
        #else
        sleep(0);
        #endif
    }

    // Retour à la ligne
    printf("\n");
}