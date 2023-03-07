#ifndef OBJECT_H
#define OBJECT_H

#include "cell.h"

typedef struct Object {
Cell *current_position;
int type_object;
} Object;

Object *object_create(Cell *start_position, int type);
void object_destroy(Object *object);

#endif