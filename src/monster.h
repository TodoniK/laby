#ifndef MONSTER_H
#define MONSTER_H

#include "cell.h"

typedef struct {
    Cell current_position;
} Monster;

Monster create_monster(Cell current_position);
Cell get_position(Monster* monster);
void move(Monster* monster, Cell new_position);
void attack_hero(Monster* monster);

#endif // MONSTER_H
