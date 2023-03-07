#include "hero.h"

// Crée un nouveau héros
Hero create_hero(Cell current_position, int current_direction, Object* list_objects, int speed) {
    Hero hero;
    hero.current_position = current_position;
    hero.current_direction = current_direction;
    hero.list_objects = list_objects;
    hero.speed = speed;
    return hero;
}

// Retourne la position actuelle du héros dans le labyrinthe
Cell get_position(Hero* hero) {
    return hero->current_position;
}

// Retourne la direction actuelle du héros (nord, sud, est, ouest)
int get_direction(Hero* hero) {
    return hero->current_direction;
}

// Déplace le héros dans le labyrinthe dans la direction spécifiée
void move(Hero* hero, int direction) {
    // TODO: implémenter la logique de déplacement
}

// Ramasse le trésor sur la case actuelle du héros
Object* pick_object(Hero* hero) {
    // TODO: implémenter la logique de ramassage d'objet
}

// Attaque le monstre sur la case actuelle du héros avec son épée
Cell attack_monster(Hero* hero) {
    // TODO: implémenter la logique d'attaque
}

// Utilise le fil d'Ariane pour retourner à l'entrée du labyrinthe
void use_aryan_thread(Hero* hero) {
    // TODO: implémenter la logique de retour en arrière avec le fil d'Ariane
}

// Change la vitesse de déplacement du héros
void change_speed(Hero* hero, int new_speed) {
    hero->speed = new_speed;
}
