// Ensemble des header
#include "main.h"

// Interface Print
#include "PrintInterface.h"

// Introduction du jeu
#include "IntroductionJeu.h"

// Jeu awale
#include "Jeu.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Entrée principale du programme
// @param : INT, Nombre d'argument passés au programme
// @param : CHAR[], Arguments sous forme de tableau
// @return : INT, Retourne un code d'erreur (0 ou 1) selon comment c'est arrêté le programme
int main(int argc, char * argv[])
{
  // Nettoi la console
  effacer_console();

  // On initialise les informations sur la console
  initialise_informations_console();

  // Introduit le jeu
  introduire_le_jeu();

  // Jeu en cour
  // Initialisation des valeurs par défaut
  JEU awale = creer_un_jeu();

  // Propose de commencer à l'utilisateur
  printf("Voulez-vous commencer ? [o/n]\n");

  // Réponse de l'utilisateur
  char reponse;

  // Attend la réponse de l'utilisateur
  scanf("%c", &reponse);

  // Vérifie la saisie de l'utilisateur
  if(reponse != 'o')
    quitter_le_jeu(&awale);

  //
  // Boucle principale du jeu
  while(est_en_execution(awale))
    {
      //
      // On efface la console
      effacer_console();

      //
      // Affiche l'interface de sortie
      affiche_interface(awale);

      //
      // Affiche l'interface d'entrée utilisateur
      interface_entree(&awale);

      //
      // @TODO
      // Traitement des données...
    }

  // Le programme c'est arrêté
  // sans problème
  return EXIT_SUCCESS;
}
