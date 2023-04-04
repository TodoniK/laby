#ifndef LABYRINTHE_H
#define LABYRINTHE_H

#include <stdio.h>
#include <stdlib.h>

/**
 * @file labyrinthe.h
 * @brief Ce fichier contient les prototypes des fonctions du labyrinthe ainsi que les commentaires associés à ces fonctions
 */

/**
 * @brief Fonction permettant d'afficher le labyrinthe
 *
 * @param[in] labyrinthe : pointeur sur la début de la chaîne de caractère représentant le labyrinthe
 * @param[in] largeur : largeur voulue du labyrinthe
 * @param[in] hauteur : hauteur voulue du labyrinthe
 */
void afficherLaby(const char *labyrinthe, int largeur, int hauteur);

/**
 * @brief Fonction implémentant l'algorithme de reverse backtracking
 *
 * @param[in] labyrinthe : pointeur sur la début de la chaîne de caractère représentant le labyrinthe
 * @param[in] largeur : largeur voulue du labyrinthe
 * @param[in] hauteur : hauteur voulue du labyrinthe
 * @param[in] x : abscisse de la case dont on veut visiter (et creuser) les voisins 
 * @param[in] y : ordonnée de la case dont on veut visiter (et creuser) les voisins
 */
void creuserLaby(char *labyrinthe, int largeur, int hauteur, int x, int y);

/**
 * @brief Fonction permettant d'initialiser le labyrinthe à un ensemble de murs, et de creuser les cases de celui-ci en appelant la fonction creuserLaby pour toutes ses cases
 *
 * @param[in] labyrinthe : pointeur sur la début de la chaîne de caractère représentant le labyrinthe
 * @param[in] largeur : largeur voulue du labyrinthe
 * @param[in] hauteur : hauteur voulue du labyrinthe
 */
void genererLaby(char *labyrinthe, int largeur, int hauteur);

#endif