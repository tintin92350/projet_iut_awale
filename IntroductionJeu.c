// Introduction de jeu
#include "IntroductionJeu.h"

// Main
#include "main.h"

// Interface Print
#include "PrintInterface.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Introduit le jeu
// @param : NO PARAM
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void introduire_le_jeu()
{
  // Légendes à afficher
  const char * legendes_text[7] = {
    "Ils ont marché longtemps, très longtemps à travers le désert...",
    "jusqu'à ce qu'ils arrivent au bord de la mer...",
    "Ils ont fait des provisions de coquillages..",
    "puis sont repartis dans leur village",
    "En chemin, ils ont fait des trous dans le sable",
    "pour stocker les coquillages.",
    "C'est ainsi qu'est né le jeu : des coquillages dans des trous"
  };

  // Affichage de chaque légende
  unsigned int legende = 0;

  // Pour chaque légende
  for(;legende < 7; legende++)
    {
      // On affiche sa valeur au entre de la console
      affichage_centre((char*)legendes_text[legende]);
      // Puis on attend 1s
      sleep(0);
    }

  // Retour à la ligne
  printf("\n");
  
  // Compteur abstrait utilisé
  unsigned int compteur;

  // On affiche 3 tirets
  // avec une animation
  for(compteur = 0; compteur < 3; compteur++)
    {
      // On affiche le tiret
      affichage_centre("-");
      // Puis on attend 1s
      sleep(0);
    }

  // Retour à la ligne
  printf("\n");
}
