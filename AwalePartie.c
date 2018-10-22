//
// AwalePartie.c
// Définis les fonctions relatives à une partie
#include "AwalePartie.h"
#include "Plateau.h"

/**
 * Créer une nouvelle partie
 * @return AwalePartie, renvoi la partie crée
 */
AwalePartie creer_partie()
{
    // Créer une structure temporaire
    AwalePartie partie;

    // Initialise le plateau à ses valeurs par défaut
    plateau_defaut(partie.plateau);

    // Le joueur 1 commence
    partie.joueur = JOUEUR_1;

    // Initialise les scores à 0
    partie.scores[0] = partie.scores[1] = 0;

    // Met la partie à l'etat initiale
    partie.etat_du_jeu = ETAT_JOUE;

    // Initialise le premier coup
    partie.premier_coup = TRUE;

    // Les joueurs ne sont pas en famine ! (pas encore...)
    partie.famines[0] = partie.famines[1] = FALSE;

    // Retourne la structure crée
    return partie;
}

/**
 * Quitte le jeu (met l'état à QUITTER)
 * @param AwalePartie, Pointeur vers la partie
 */
void quitter_partie(AwalePartie * partie)
{
    partie->etat_du_jeu = ETAT_QUITTER;
}

/**
 * Affiche le dernier coup joué par un joueur
 * @param AwalePartie, Partie en cours
 */
void afficher_dernier_coup_joue(const AwalePartie partie)
{
    // On quit si c'est le premier coup
    if(partie.premier_coup)
        return;

    // On convertit le numéro en caractere
    char emp_alpha = partie.dernier_emplacement.y == 0 ? partie.dernier_emplacement.x + 'a' : partie.dernier_emplacement.x + 'A';

    // Affiche sur la console
    printf("Le dernier coup à été joué par le joueur %d : %c\n", partie.dernier_emplacement.y + 1, emp_alpha);
}

/**
 * La partie est toujours en train de continuer
 * @parm AwalePartie, la partie en cours
 * @return FLAG, l'etat du jeu est JOUER
 */
FLAG est_en_execution(const AwalePartie partie)
{
    return partie.etat_du_jeu == ETAT_JOUE;
}