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

  // Initialise les scores
  jeu.scores[0] = jeu.scores[1] = 0;

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
  //while((!case_est_valide(case_joueur)) && (!case_est_au_joueur(case_joueur, jeu->joueur)) && case_est_vide(jeu->plateau, case_joueur, jeu->joueur));
  while((!case_est_valide(case_joueur) + !case_est_au_joueur(case_joueur, jeu->joueur) + case_est_vide(jeu->plateau, case_joueur, jeu->joueur)));

  jeu->case_joueur = case_joueur;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Affiche les informations relatives
// au jeu
// @param : JEU, le jeu en question
void affiche_informations_partie(JEU jeu)
{
  char joueur[9];
  char gain[9];

  sprintf(joueur, "JOUEUR %d", jeu.joueur + 1);
  sprintf(gain,   "GAIN : %d", jeu.scores[jeu.joueur]);

  // On affiche les informations sur la partie en cour
  affichage_droite_gauche(joueur, gain);

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

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Donne le numéro d'une case
// par rapport à son numéro ASCII
// @param char, Case selectionnée
// @return int, Le numéro de la case
unsigned int numero_case(const char c)
{
  return (c >= 'a' && c <= 'f') ? c - 'a' : c - 'A';
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Fonction jouer
// Avec des informations correctement vérifié au préalable
// permet de jouer une case
// @param 2d-array, La plateau du jeu
// @param char, L'entrée utilisateur
// @param int, Joueur qui joue
void jouer_coup(JEU * jeu)
{
  // Recupère les informations nécessaire
  // comme raccourcie
  FLAG joueur = jeu->joueur;
  FLAG case_joueur = numero_case(jeu->case_joueur);

  // Curseur pour le déplacement en x et y
  int curseur_x = case_joueur;
  int curseur_y = joueur;

  // Direction
  int vecteur_dir = joueur == 0 ? -1 : 1;

  // Recupère la valeur de la case demande
  // soit le nombre de graine
  int nbr_graine = jeu->plateau[joueur][curseur_x];


  // Une boucle pour le nombre de graine
  for(;jeu->plateau[joueur][case_joueur] > 0;jeu->plateau[joueur][case_joueur]--)
    {
      // On vérifie que la case courente n'est pas celle de départ
      if(curseur_x == case_joueur && curseur_y == joueur)
        jeu->plateau[joueur][case_joueur]++;
      else
        {
          // Changement de direction
          // lorsque le curseur arrive
          // à une des extrémité
          if((curseur_x >= 5 && vecteur_dir == 1) || (curseur_x <= 0 && vecteur_dir == -1))
            {
              curseur_y = (curseur_y + 1) % 2;

              // Modifie le plateau
              jeu->plateau[curseur_y][curseur_x] += 1;

              vecteur_dir *= -1;
              nbr_graine--;
            }
          else
            {
              // Increment ou Desincrement
              // le curseur en x selon la direction
              curseur_x += vecteur_dir;

              // Modifie le plateau
              jeu->plateau[curseur_y][curseur_x] += 1;
            }
        }
    }

  // Recupere le nombre de graine
  // dans la dernière case
  // atteint par le joueur
  unsigned int nbr_graine_derniere_case = jeu->plateau[curseur_y][curseur_x];

  // On vérifie si elle contient le nombre de graine
  // souhaité pour le prendre
  while(curseur_y != jeu->joueur && (nbr_graine_derniere_case == 2 || nbr_graine_derniere_case == 3))
    {
      jeu->scores[jeu->joueur] += nbr_graine_derniere_case;
      jeu->plateau[curseur_y][curseur_x] = 0;

      curseur_x += vecteur_dir;

      if(curseur_x < 0 || curseur_x > 5)
        break;
      nbr_graine_derniere_case = jeu->plateau[curseur_y][curseur_x];
    }
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
  FLAG boolean = 0;

  // Joueur 1
  if(joueur == 0)
    boolean = cas >= 'a' && cas <= 'f';
  // Joueur 2
  else if(joueur == 1)
      boolean = cas >= 'A' && cas <= 'F';

  if(!boolean)
    printf("Cette case ne vous appartient pas !\n");

  return boolean;
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

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Vérifie si la case demandée est vide
// @param 2d-array, plateau du jeu
// @param char, L'entrée utilisateur à tester
// @param int, Joueur qui jou 
// @return : FLAG, Retourne une valeur boolean par rapport aux tests
FLAG case_est_vide(const graine plateau[2][6], const char case_j, const unsigned int joueur)
{
  unsigned int ncase = numero_case(case_j);
  if(ncase < 6)
    return plateau[joueur][numero_case(case_j)] == 0;
  return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Vérifie si le joueur à gagné selon
// quelques règles
// @param : Jeu
// @return : FLAG
FLAG joueur_a_gagner(const JEU jeu)
{
  return (jeu.scores[jeu.joueur] > 24);
}
