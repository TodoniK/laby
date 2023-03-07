#include "cell.h"

#include <stdio.h>
#include <stdlib.h>

// Crée une nouvelle cellule avec les attributs passés en paramètre
Cell *cell_create(int x, int y, int type, bool is_entry) {

    Cell *cell = malloc(sizeof(Cell));

    if (cell == NULL) {
        perror("Error: unable to allocate memory for Cell");
        exit(EXIT_FAILURE);
    }

    cell->abs_x = x;
    cell->ord_y = y;
    cell->type_case = type;
    cell->est_entree = is_entry;
    
    return cell;
}

// Détruit une cellule et libère la mémoire allouée pour elle
void cell_destroy(Cell *cell) {
    free(cell);
}

// Retourne un tableau de pointeurs vers les cellules voisines accessibles depuis cette cellule
Cell **cell_get_neighbours(Cell *cell) {

    Cell **neighbours = malloc(4 * sizeof(Cell *));

    if (neighbours == NULL) {
        perror("Error: unable to allocate memory for neighbours");
        exit(EXIT_FAILURE);
    }

    int index = 0;

    if (cell->abs_x > 0) {
        neighbours[index] = &cell_create(cell->abs_x - 1, cell->ord_y, 0, false);
        index++;
    }

    if (cell->abs_x < MAZE_WIDTH - 1) {
        neighbours[index] = &cell_create(cell->abs_x + 1, cell->ord_y, 0, false);
        index++;
    }
    
    if (cell->ord_y > 0) {
        neighbours[index] = &cell_create(cell->abs_x, cell->ord_y - 1, 0, false);
        index++;
    }

    if (cell->ord_y < MAZE_HEIGHT - 1) {
        neighbours[index] = &cell_create(cell->abs_x, cell->ord_y + 1, 0, false);
        index++;
    }

    neighbours = realloc(neighbours, index * sizeof(Cell *));

    if (neighbours == NULL && index > 0) {
        perror("Error: unable to reallocate memory for neighbours");
        exit(EXIT_FAILURE);
    }

    return neighbours;
}

