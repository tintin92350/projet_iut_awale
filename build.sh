#!/bin/bash

# Files for compilation
files="main.c PrintInterface.c IntroductionJeu.c Jeu.c"

# Name of out file
out="awale"

# Options for compilation
opts="-Wall -g"

# Remove last awale executable
rm $out

# Clear console
clear

# Start compilation
gcc $files -o $out $opts