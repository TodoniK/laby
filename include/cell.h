#ifndef CELL_H
#define CELL_H

#include <stdbool.h>
#include <stdlib.h>

enum cell { Wall, Corridor, North, East, West, South }; /* Représente les différentes possibilités de type de cellule : soit couloir, soit mur. */

/* Constructeur d'une cellule. Une cellule est composée de sa position dans la grille (matrice), représentée par x et y. Elle contient un objet et une fleche menant vers la sortie. Elle peut être soit couloir soit mur. */
typedef struct {

enum cell type_case;

} t_cell;

#endif