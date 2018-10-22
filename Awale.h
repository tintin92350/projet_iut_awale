//
// Awale.h
// Définit toutes les fonctions relatives au jeu awale
#ifndef __AWALE_HEADERFILE__
#define __AWALE_HEADERFILE__

// En-têtes
#include "main.h"

// Fichiers du jeu
#include "Emplacement.h"
#include "AwalePartie.h"

/*******************************************************************************
 * FONCTIONS D'AFFICHAGE DES INFORMATIONS
 ******************************************************************************/

/**
 * Afficher le score des joueurs
 * @param unsigned int[2], Les scores des joueurs
 */
void afficher_scores(const unsigned int scores[2]);

/*******************************************************************************
 * FONCTIONS DU JEU
 ******************************************************************************/

/**
 * Demande à l'utilisateur un emplacement
 * @param AwalePartie, la partie en cours
 * @return Emplacement, retourne l'emplacement demandé
 */
Emplacement demande_emplacement_au_joueur(AwalePartie * partie);

/**
 * Fonction qui permet de jouer un coup selon l'emplacement
 * @param Plateau - 2Dimensions, Le plateau de jeu
 * @param Emplacement, L'emplacement où prendre les graines
 * @return Emplacement, Renvoi la dernière case
 */
Emplacement jouer_coup(int plateau[2][6], const Emplacement empGraines);

/**
 * Fonction qui ramasse si possible les graines
 * @param Plateau - 2Dimensions, Le plateau de jeu
 * @param Emplacement, L'emplacement où prendre les graines
 * @param unsigned int, Le joueur qui vient de jouer
 * @return unsigned int, Le nombre de graine obtenue
 */
unsigned int ramasser_graines(int plateau[2][6], Emplacement empGraines, const unsigned int joueur);

/**
 * Fonction qui renvoi le joueur suivant
 * @param unsigned int, Joueur actuel
 * @return unsigned int, Joueur suivant
 */
unsigned int joueur_suivant(const unsigned int joueur);

/*******************************************************************************
 * FONCTIONS DE CONVERSION
 ******************************************************************************/

/**
 * Fonction qui convertit un caractère en sa coordonnée x dans le plateau
 * @param char, Le caractère à convertir
 * @return int, Renvoie la coordonnée ou -1 (erreur)
 */
int conversion_char_vers_coordonnee_x(const char entree);

/*******************************************************************************
 * FONCTIONS DE VERIFICATION
 ******************************************************************************/

/**
 * Vérifie si l'entrée utilisateur est standard
 * @param char, l'entrée utilisateur
 * @return BOOL
 */
BOOL entree_utilisateur_est_standard(const char entree);

/**
 * Vérifie si la case entrée par l'utilisateur lui appartient
 * @param char, Entrée à tester
 * @param unsigned int, Utilisateur en question
 * @return BOOL
 */
BOOL entree_appartient_a_utilisateur(const char entree, const unsigned int joueur);

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
BOOL entree_respecte_regles(const char entree, const unsigned int joueur, const int plateau[2][6], const BOOL joueur_suivant_famine, AwalePartie * awale);

/**
 * Vérifie si l'emplacement est propice à un ramassage
 * @param Plateau - 2Dimensions, Le plateau de jeu
 * @param Emplacement, L'emplacement à vérifier
 * @param unsigned int, Le joueur qui vient de jouer
 * @return BOOL
 */
BOOL emplacement_est_ramassable(const int plateau[2][6], const Emplacement emp, const unsigned int joueur);

/**
 * Vérifie si le joueur j est en famine
 * @param Plateau - 2Dimensions, Le plateau de jeu
 * @param unsigned int, Le joueur qui vient de jouer 
 * @return BOOL
 */
BOOL joueur_en_famine(const int plateau[2][6], const unsigned int joueur);

/**
 * Vérifie si un joueur peut nourrie son adversaire
 * @param Plateau - 2Dimensions, Le plateau de jeu
 * @param unsigned int, Le joueur qui vient de jouer 
 * @return BOOL
 */
BOOL joueur_peut_nourrire(const int plateau[2][6], const unsigned int joueur);

/**
 * Vérifie en cas de famine si le joueur peut jouer cette case
 * @param Plateau - 2Dimensions, Le plateau de jeu
 * @param unsigned int, Le joueur qui vient de jouer 
 * @param Emplacement, l'emplacement à tester
 */
BOOL joueur_peut_jouer_cette_case_famine(const int plateau[2][6], const unsigned int joueur, const Emplacement emp);

#endif