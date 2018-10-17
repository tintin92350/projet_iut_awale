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

  // Joueur en cours
  FLAG joueur;

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
FLAG est_en_execution(const JEU);

// Initialise le plateau de jeu
// @param : graine[], Tableau de grain (plateau)
void initialise_plateau(graine plateau[NOMBRE_JOUEUR][NOMBRE_CASE_JOUEUR]);

// Affiche l'interface du jeu
// @param : JEU, le jeu en question
void affiche_interface(JEU);

// Interface d'entrée utilisateur
// @param : JEU, le jeu en question
void interface_entree(JEU *);

// Affiche les informations relatives
// au jeu
// @param : JEU, le jeu en question
void affiche_informations_partie(JEU);

// Affiche le plateau de jeu
// @param : JEU, le jeu en question
void affiche_plateau(JEU);

// Quitter le jeu
// @param : JEU, le jeu en question
void quitter_le_jeu(JEU *);

////////////////////////////////////////////////////////////////////////////////////////////////////////
// FONCTIONS DE VERIFICATIONS DES DONNEES
////////////////////////////////////////////////////////////////////////////////////////////////////////

// Vérifie si la case en question
// appartient au joueur
// @param : CHAR, L'entrée utilisateur à tester
// @param : FLAG, Le joueur qui vient de jouer
// @return : FLAG, Retourne une valeur boolean par rapport aux tests
FLAG case_est_au_joueur(const char, const FLAG);

// Vérifie si le joueur a entrée des informations
// cohérentes (les cases)
// @param : CHAR, L'entrée utilisateur à tester
// @return : FLAG, Retourne une valeur boolean par rapport aux tests
FLAG case_est_valide(const char);


#endif // Jeu
