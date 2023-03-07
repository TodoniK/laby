#ifndef CELL_H
#define CELL_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct Cell {
int abs_x;
int ord_y;
int type_case;
bool est_entree;
} Cell;

Cell *cell_create(int x, int y, int type, bool is_entry);
void cell_destroy(Cell *cell);

Cell **cell_get_neighbours(Cell *cell);
Cell **cell_get_walls(Cell *cell);
bool cell_contain_monster(Cell *cell);
bool cell_contain_object(Cell *cell);
bool cell_contain_aryan_wire(Cell *cell);

#endif

