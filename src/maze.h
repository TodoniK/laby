#ifndef MAZE_H
#define MAZE_H

#include <stdbool.h>
#include "cell.h"

typedef struct Maze {
int width;
int height;
Cell **grid;
} Maze;

Maze *maze_create(int width, int height);
void maze_destroy(Maze *maze);

void maze_generate(Maze *maze);
void maze_display(Maze *maze);
bool maze_verify(Maze *maze);
Cell *maze_find_enter(Maze *maze);
Cell **maze_list_objects(Maze *maze);
Cell **maze_list_monsters(Maze *maze);

#endif