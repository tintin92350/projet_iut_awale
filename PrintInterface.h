//
// PrintInterface.h
// Ensemble de fonctions pour imprimé / afficher du text
// sur la console de facon plus "animé"
#ifndef __PRINT_INTERFACE_HEADER_FILE__
#define __PRINT_INTERFACE_HEADER_FILE__

// En-tête requis
#include "main.h"

// Structure récuperant des informations
// sur la console
static struct winsize CONSOLE_SIZE;

// Initialise la structure d'information sur la console
// @param : NO PARAMS
void initialise_informations_console();

// Donne la lergeur de la console
// @param : NO PARAMS
// @return : UINT, la largeur de la console
unsigned int largeur_console();

// Affiche un text brut de facon centré sur la console
// @param : STRING, la chaine de caractère à afficher
void affichage_centre(char *);

// Affiche 2 textes opposé (droite - gauche)
// @param : STRING, première chaine de caractère (gauche)
// @param : STRING, deuxième chaine de caractère (droite)
void affichage_droite_gauche(char *, char *);

// Affiche une bar de séparation
void affiche_separation_horizontal();

// Affiche le plateau centré
// @param : ARRAY, Le tableau de graine
void afficher_plateau(graine plateau[NOMBRE_JOUEUR][NOMBRE_CASE_JOUEUR]);

// Efface la console
// @param : NO PARAMS
void effacer_console();

#endif // Print Interface
