#ifndef HERO_H
#define HERO_H

#include <stdbool.h>
#include "maze.h"
#include "object.h"

typedef struct Hero {
Cell *current_position;
int current_direction;
bool has_sword;
int speed;
} Hero;

Hero *hero_create(Cell *start_position);
void hero_destroy(Hero *hero);

void hero_move(Hero *hero, int direction);
Object *hero_pick_object(Hero *hero);
Cell *hero_attack(Hero *hero);
void hero_use_aryan_thread(Hero *hero, Maze *maze);
void hero_change_speed(Hero *hero, int speed_change);

#endif