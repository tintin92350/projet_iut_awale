//
// Jeu.h
// Ensemble des éléments nécessaire au fonctionnement du jeu
#ifndef __JEU_HEADER_FILE__
#define __JEU_HEADER_FILE__

// Requière des en-tête supplémentaires
#include "main.h"

//
// Structure contenant les informations
// Du jeu courant
typedef struct s_Jeu
{
  // Plateau du jeu
  // Un tableau en 2-Dimensions
  graine plateau[NOMBRE_JOUEUR][NOMBRE_CASE_JOUEUR];

  // Etat du jeu (EN COUR, TERMINER)
  FLAG etat_du_jeu;

  // @TODO :
  // Ajouter des éléments

} JEU;

// Créer un nouveau jeu
// @param : NO PARAMS
// @return : JEU (struct), la structure de JEU ainsi crée
JEU creer_un_jeu();

// Le jeu s'execute-t-il toujour ?
// @param : JEU, le jeu en question
// @return : FLAG, l'etat du jeu
FLAG est_en_execution(const JEU jeu);

// Initialise le plateau de jeu
// @param : graine[], Tableau de grain (plateau)
void initialise_plateau(graine plateau[NOMBRE_JOUEUR][NOMBRE_CASE_JOUEUR]);

// Affiche le plateau de jeu
// @param : JEU, le jeu en question
void affiche_plateau(JEU jeu);

// Quitter le jeu
// @param : JEU, le jeu en question
void quitter_le_jeu(JEU * jeu);

#endif // Jeu
