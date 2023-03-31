#ifndef LABYRINTHE_H
#define LABYRINTHE_H

#include <stdio.h>
#include <stdlib.h>

/* Fonction permettant d'afficher le labyrinthe. Prend en entrée le labyrinthe (pointeur sur la début de la chaîne de caractère), la hauteur et la largeur du labyrinthe */
void afficherLaby(const char *labyrinthe, int largeur, int hauteur);

/*  Fonction implémentant l'algorithme de reverse backtracking. Prend en paramètre le pointeur sur le début du labyrinthe, la hauteur et largeur de celui-ci, 
    ainsi que la position de la case dont on veut visiter (et creuser) les voisins */
void creuserLaby(char *labyrinthe, int largeur, int hauteur, int x, int y);

/* Fonction permettant d'initialiser le labyrinthe à un ensemble de murs, et de creuser les cases de celui-ci en appelant la fonction creuserLaby pour toutes ses cases */
void genererLaby(char *labyrinthe, int largeur, int hauteur);

#endif