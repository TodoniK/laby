#ifndef OBJECT_H
#define OBJECT_H

#include "cell.h"

typedef struct {
    Cell current_position;
    int type_object;
} Object;

Object create_object(Cell current_position, int type_object);
Cell get_position(Object* object);
int get_type(Object* object);
void move(Object* object, Cell new_position);

#endif // OBJECT_H
