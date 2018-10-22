//
// AwalePartie.h
// Définit la structure d'une partie (données)
#ifndef __AWALE_PARTIE_HEADERFILE__
#define __AWALE_PARTIE_HEADERFILE__

// En-têtes
#include "main.h"

// Fichiers du jeu
#include "AwaleConstant.h"
#include "Emplacement.h"

// Structure partie
typedef struct s_AwalePartie
{
    // Plateau de jeu
    int plateau[2][6];

    // Scores des joueurs
    unsigned int scores[2];

    // Joueur qui est en train de jouer
    unsigned int joueur;

    // l'Emplacement demandé
    Emplacement emplacement;
    // Dernier emplacement joué
    Emplacement dernier_emplacement;

    // Permier coup ?
    BOOL premier_coup;

    // Stock l'etat famine des joueurs
    BOOL famines[2];

    // Etat du jeu
    FLAG etat_du_jeu;

} AwalePartie;

/*******************************************************************************
 * FONCTIONS POUR LA PARTIE
 ******************************************************************************/

/**
 * Créer une nouvelle partie
 * @return AwalePartie, renvoi la partie crée
 */
AwalePartie creer_partie();

/**
 * Quitte le jeu (met l'état à QUITTER)
 * @param AwalePartie, Pointeur vers la partie
 */
void quitter_partie(AwalePartie * partie);

/**
 * Affiche le dernier coup joué par un joueur
 * @param AwalePartie, Partie en cours
 */
void afficher_dernier_coup_joue(const AwalePartie partie);

/**
 * La partie est toujours en train de continuer
 * @parm AwalePartie, la partie en cours
 * @return FLAG, l'etat du jeu est JOUER
 */
FLAG est_en_execution(const AwalePartie partie);

#endif