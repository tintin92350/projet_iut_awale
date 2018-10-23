#! /bin/bash

# Fichiers à compiler
fichiers="main.c Emplacement.c IOExtends.c Plateau.c Awale.c AwalePartie.c"

# Nom de l'executable à générer
exec="Awale"

# Options
opts="-Wall -g -std=c99"

# Compile le programme
gcc $fichiers -o $exec $opts