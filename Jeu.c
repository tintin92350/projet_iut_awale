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

  // Initialise le joueur
  jeu.joueur = 0;

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
// Affiche l'interface du jeu
// @param : JEU, le jeu en question
void affiche_interface(JEU jeu)
{
  // Affiche les informations relative
  // à la partie en cours
  affiche_informations_partie(jeu);

  // On affiche le plateau
  affiche_plateau(jeu);

  // On affiche une séparation
  affiche_separation_horizontal(0);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Interface d'entrée utilisateur
// @param : JEU, le jeu en question
void interface_entree(JEU * jeu)
{
  // Affiche la demande à l'utilisateur
  printf("Qu'elle case voulez-vous mouvoire ?\n");

  // Entrée utilisateur
  char case_joueur;

  // Demande à l'utilisateur
  // de rentrée une valeur char qui correspond
  // a une case de son terrain
  do
    {
      scanf(" %c", &case_joueur);
    }
  while(!case_est_valide(case_joueur) && !case_est_au_joueur(case_joueur, jeu->joueur));
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Affiche les informations relatives
// au jeu
// @param : JEU, le jeu en question
void affiche_informations_partie(JEU jeu)
{
  // On affiche les informations sur la partie en cour
  affichage_droite_gauche("JOUEUR 1", "3 Coups");

  // On affiche une séparation
  affiche_separation_horizontal(0);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Affiche le plateau de jeu
// @param : JEU, le jeu en question
void affiche_plateau(JEU jeu)
{
  // Saute 3 lignes
  printf("\n\n\n");
  // Affiche le plateau du jeu
  afficher_plateau(jeu.plateau);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Quitter le jeu
// @param : JEU, le jeu en question
void quitter_le_jeu(JEU * jeu)
{
  jeu->etat_du_jeu = ETAT_TERMINER;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// FONCTIONS DE VERIFICATIONS DES DONNEES
////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Vérifie si la case en question
// appartient au joueur
// @param : CHAR, L'entrée utilisateur à tester
// @param : FLAG, Le joueur qui vient de jouer
// @return : FLAG, Retourne une valeur boolean par rapport aux tests
FLAG case_est_au_joueur(const char cas, const FLAG joueur)
{
  // Joueur 1
  if(joueur == 0)
    return cas >= 'a' && cas <= 'f';
  // Joueur 2
  else if(joueur == 1)
    return cas >= 'A' && cas <= 'F';

  return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Vérifie si le joueur a entrée des informations
// cohérentes (les cases)
// @param : CHAR, L'entrée utilisateur à tester
// @return : FLAG, Retourne une valeur boolean par rapport aux tests
FLAG case_est_valide(const char cas)
{
  FLAG boolean = (cas >= 'a' && cas <= 'f') || (cas >= 'A' && cas <= 'F');

  if(!boolean)
    printf("La case demandée est invalide !\n");

  return boolean;
}
