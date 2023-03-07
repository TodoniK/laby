#ifndef MONSTER_H
#define MONSTER_H

#include "cell.h"

typedef struct Monster {
Cell *current_position;
} Monster;

Monster *monster_create(Cell *start_position);
void monster_destroy(Monster *monster);

void monster_attack_hero(Monster *monster);

#endif