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
    int xEntree;
    int yEntree;
    int genere;
    int resolu;
} Labyrinthe;

/**
 * @brief Structure de case possible
 */

typedef enum {COULOIR,MUR,NORD,SUD,EST,OUEST,MAX} enumCaractere;

/**
 * @brief Fonction permettant de retourner la valeur située dans la case en x,y
 *
 * @param[in] x : abscisse de la case souhaitée
 * @param[in] y : ordonnée de la case souhaitée
 * @return Retourne la valeur contenu à la case en x,y
 */

int getValeurCase(Labyrinthe lab, int x, int y);

/**
 * @brief Fonction permettant de mettre à jour la valeur située dans la case en x,y
 *
 * @param[in] x : abscisse de la case souhaitée
 * @param[in] y : ordonnée de la case souhaitée
 */

void setValeurCase(Labyrinthe lab, int x, int y, int nouvelleValeur);

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

/**
 * @brief Fonction permettant de placer la fleche vers l'entrée
 *
 * @param[in] directionActuelle : direction actuelle dans laquelle on creuse
 */

int getDirectionOpposee(int directionActuelle);

#endif /* LABYRINTHE_H */