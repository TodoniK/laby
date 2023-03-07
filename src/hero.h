#ifndef HERO_H
#define HERO_H

#include "cell.h"
#include "object.h"

typedef struct {
    Cell current_position;
    int current_direction;
    Object* list_objects;
    int speed;
} Hero;

Hero create_hero(Cell current_position, int current_direction, Object* list_objects, int speed);
Cell get_position(Hero* hero);
int get_direction(Hero* hero);
void move(Hero* hero, int direction);
Object* pick_object(Hero* hero);
Cell attack_monster(Hero* hero);
void use_aryan_thread(Hero* hero);
void change_speed(Hero* hero, int new_speed);

#endif // HERO_H
