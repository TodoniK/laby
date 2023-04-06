#ifndef LABYRINTHE_H
#define LABYRINTHE_H

#include <stdio.h>
#include <stdlib.h>

/**
 * @file labyrinthe.h
 * @brief Ce fichier contient les prototypes des fonctions du labyrinthe ainsi que les commentaires associés à ces fonctions
 */

/**
 * @brief Structure du labyrinthe
 */
typedef struct {
    char *grille;
    int hauteur;
    int largeur;
} Labyrinthe;

/**
 * @brief Structure de case possible
 */
//typedef enum {COULOIR='  ',MUR='██',NORD='↑',SUD='↓',EST='→',OUEST='←'} caractereAffiche;
typedef enum {COULOIR,MUR,NORD,SUD,EST,OUEST,MAX} enumCaractere;
//char caracteresAffiche[MAX] = {' ', 0xDB, 0x18, 0x19, 0x1A, 0x1B};

/**
 * @brief Fonction permettant de retourner la valeur située dans la case en x,y
 *
 * @param[in] x : abscisse de la case souhaitée
 * @param[in] y : ordonnée de la case souhaitée
 */
int getValeurCase(Labyrinthe lab, int x, int y);

/**
 * @brief Fonction permettant de mettre à jour la valeur située dans la case en x,y
 *
 * @param[in] x : abscisse de la case souhaitée
 * @param[in] y : ordonnée de la case souhaitée
 */
void setValeurCase(Labyrinthe lab, int x, int y);

/**
 * @brief Fonction permettant d'afficher le labyrinthe
 *
 * @param[in] lab : pointeur sur la structure du labyrinthe
 */
void afficherLaby(Labyrinthe lab);

/**
 * @brief Fonction implémentant l'algorithme de reverse backtracking
 *
 * @param[in] lab : pointeur sur la structure du labyrinthe
 * @param[in] x : abscisse de la case dont on veut visiter (et creuser) les voisins 
 * @param[in] y : ordonnée de la case dont on veut visiter (et creuser) les voisins
 */
void creuserLaby(Labyrinthe lab, int x, int y);

/**
 * @brief Fonction permettant d'initialiser le labyrinthe à un ensemble de murs, et de creuser les cases de celui-ci en appelant la fonction creuserLaby pour toutes ses cases
 *
 * @param[in] lab : pointeur sur la structure du labyrinthe
 */
void genererLaby(Labyrinthe lab);

#endif