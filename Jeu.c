// Jeu en-tête
#include "Jeu.h"

// Print
#include "PrintInterface.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Créer un nouveau jeu
// @param : NO PARAMS
// @return : JEU (struct), la structure de JEU ainsi crée
JEU creer_un_jeu()
{
  // Créer une structure de jeu à renvoyé
  JEU jeu;

  // Définit l'etat du jeu par défaut
  jeu.etat_du_jeu = ETAT_EXECUTION;

  // Initialise le plateau
  initialise_plateau(jeu.plateau);

  // Retourne le jeu
  return jeu;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Le jeu s'execute-t-il toujour ?
// @param : NO PARAMS
// @return : FLAG, l'etat du jeu
FLAG est_en_execution(const JEU jeu)
{
  return jeu.etat_du_jeu;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Initialise le plateau de jeu
// @param : graine[], Tableau de grain (plateau)
void initialise_plateau(graine plateau[NOMBRE_JOUEUR][NOMBRE_CASE_JOUEUR])
{
  // Variable pour parcourir
  // le tableau
  FLAG i, j;

  // Rempli le tableau
  for(j = 0; j < NOMBRE_JOUEUR; j++)
      for(i = 0; i < NOMBRE_CASE_JOUEUR; i++)
        plateau[j][i] = 4;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Affiche le plateau de jeu
// @param : JEU, le jeu en question
void affiche_plateau(JEU jeu)
{
  // On affiche les informations sur la partie en cour
  affichage_droite_gauche("JOUEUR 1", "3 Coups");

  // On affiche une séparation
  affiche_separation_horizontal();

  // Saute 3 lignes
  printf("\n\n\n");

  // Affiche le plateau du jeu
  afficher_plateau(jeu.plateau);
}

// Quitter le jeu
// @param : JEU, le jeu en question
void quitter_le_jeu(JEU * jeu)
{
  jeu->etat_du_jeu = ETAT_TERMINER;
}
