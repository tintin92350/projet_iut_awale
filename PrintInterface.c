// Print Interface header
#include "PrintInterface.h"

// Headers requis
// Standar C
#include "main.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Initialise la structure d'information sur la console
// @param : NO PARAMS
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void initialise_informations_console()
{
  // Fonction permettant la récuperation
  // des informations sur la taille
  // de la console
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &CONSOLE_SIZE);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Donne la lergeur de la console
// @param : NO PARAMS
// @return : UINT, la largeur de la console
/////////////////////////////////////////////////////////////////////////////////////////////////////////
unsigned int largeur_console()
{
  return CONSOLE_SIZE.ws_col;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Affiche un text brut de facon centré sur la console
// @param : STRING, la chaine de caractère à afficher
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void affichage_centre(char * str)
{
  // Récupère le nombre de caractere de la chaine
  unsigned int chaine_taille = strlen(str);
  // Récupère la taille de la console en largeur
  unsigned int console_largeur = CONSOLE_SIZE.ws_col;

  // On vérifie que la taille de la chaine n'est
  // pas supérieur à la taille de la console
  if(chaine_taille > console_largeur)
    return;

  // On affiche des espaces
  // pour l'alignement
  unsigned int space = 0;
  for(;space < console_largeur / 2 - chaine_taille / 2; space++)
    printf(" ");

  // Enfin on affiche la chaine de caractères
  printf("%s\n", str);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Affiche 2 textes opposé (droite - gauche)
// @param : STRING, première chaine de caractère (gauche)
// @param : STRING, deuxième chaine de caractère (droite)
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void affichage_droite_gauche(char * str1, char * str2)
{
  // On vérifie si la taille additionné
  // des deux chaines ne dépasse pas
  // la longueur de la console
  // si c'est la cas on affiche les deux par saut de ligne (défautt)
  if(strlen(str1) + strlen(str2) > largeur_console())
    {
      printf("%s\n%s", str1, str2);
    }
  else
    {
      // On affiche la première chaine de caractère
      printf("%s", str1);

      // On récupère l'espace entre les deux
      unsigned int espace_max = largeur_console() - strlen(str2) - strlen(str1);

      // On affiche les espaces souhaités
      unsigned int espace;
      for(espace = 0; espace < espace_max; espace++)
        printf(" ");

      // On affiche le deuxième text
      printf("%s\n", str2);
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Affiche une bar de séparation
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void affiche_separation_horizontal(unsigned int largeur)
{
  unsigned int i;
  unsigned int vrai_largeur = largeur == 0 ? largeur_console() : largeur;
  for(i = 0;i<vrai_largeur; i++)
    printf("-");
  printf("\n");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Affiche le plateau centré
// @param : ARRAY, Le tableau de graine
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void afficher_plateau(graine plateau[NOMBRE_JOUEUR][NOMBRE_CASE_JOUEUR])
{
  // Affiche les cases du joueur 1
  affichage_centre("[a] [b] [c] [d] [e] [f]");

  // Les differents cases du joueur (avec séprations verticales)
  char joueur_1_cases[26];
  char joueur_2_cases[26];

  // Format
  sprintf(joueur_1_cases, "| %d | %d | %d | %d | %d | %d |", plateau[0][0], plateau[0][1], plateau[0][2], plateau[0][3], plateau[0][4], plateau[0][5]);

  // Format des cases du joueur 2
  sprintf(joueur_2_cases, "| %d | %d | %d | %d | %d | %d |", plateau[1][0], plateau[1][1], plateau[1][2], plateau[1][3], plateau[1][4], plateau[1][5]);

  // Séparation
  affichage_centre("-------------------------");

  // On l'affiche
  affichage_centre(joueur_1_cases);

  // On affiche la séparation horizontal
  affichage_centre("-------------------------");

  // On l'affiche
  affichage_centre(joueur_2_cases);

  // On affiche la séparation horizontal
  affichage_centre("-------------------------");

  // Affiche les cases du joueur 2
  affichage_centre("[A] [B] [C] [D] [E] [F]");

  // Saute 3 lignes
  printf("\n\n\n");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Efface la console
// @param : NO PARAMS
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void effacer_console()
{
  system("clear");
}
