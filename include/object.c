#include "object.h"

// Crée un nouvel objet
Object create_object(Cell current_position, int type_object) {
    Object object;
    object.current_position = current_position;
    object.type_object = type_object;
    return object;
}

// Retourne la position actuelle de l'objet dans le labyrinthe
Cell get_position(Object* object) {
    return object->current_position;
}

// Retourne le type de l'objet
int get_type(Object* object) {
    return object->type_object;
}

// Change la position de l'objet dans le labyrinthe
void move(Object* object, Cell new_position) {
    object->current_position = new_position;
}
