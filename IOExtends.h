//
// PrintExtend.h
// Ensemble de fonctions pour imprimé / afficher du text
// sur la console de facon plus "animé"
#ifndef __IOEXTENDS_HEADER_FILE__
#define __IOEXTENDS_HEADER_FILE__

// En-tête requis
#include "main.h"

// Fichiers du jeu
#include "AwaleTypes.h"
#include "AwalePartie.h"

/**
 * Initialise la structure d'information sur la console
 */
void initialise_informations_console();

/**
 *  Donne la lergeur de la console
 * @return unsigned int, la largeur de la console
 */
unsigned int largeur_console();

/**
 * Affiche un text brut de facon centré sur la console
 * @param string, la chaine de caractère à afficher
 */
void affichage_centre(const string);

/**
 * Affiche 2 textes opposé (droite - gauche)
 * @param string, première chaine de caractère (gauche)
 * @param string, deuxième chaine de caractère (droite)
 */
void affichage_droite_gauche(const string, const string);

/**
 *  Affiche une bar de séparation
 */
void affiche_separation_horizontal();

/**
 * Efface la console
 */
void effacer_console();


/*******************************************************************************
 * FONCTIONS SUR FICHIERS
 ******************************************************************************/

/**
 * Enregistre la partie dans un fichier
 * @param string, Nom du fichier
 * @param AwalePartie, Partie à enregistrer
 * @return BOOL, La fonction a t-elle bien enregistrer la partie
 */
BOOL enregistrer_partie(const string name, AwalePartie * partie);

/**
 * Récupère la partie à partie d'un fichier
 * @param string, Nom du fichier
 * @param AwalePartie, Partie à enregistrer
 * @return BOOL, La fonction a t-elle bien enregistrer la partie
 */
BOOL recuperer_partie(const string name, AwalePartie * partie);

/**
 * Enregistre le score dans le Hall of fame
 * @param string, Nom du fichier
 * @param unsigned int, Joueur
 * @param unsigned int, Score
 * @return BOOL
 */
BOOL enregistre_score(const string name, unsigned int joueur, unsigned int score);

/**
 * Vérifie si un fichier existe
 * @param string, Nom du fichier
 * @return BOOL
 */
BOOL fichier_exist(const string name);

#endif