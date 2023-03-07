#include "monster.h"

// Crée un nouveau monstre
Monster create_monster(Cell current_position) {
    Monster monster;
    monster.current_position = current_position;
    return monster;
}

// Retourne la position actuelle du monstre dans le labyrinthe
Cell get_position(Monster* monster) {
    return monster->current_position;
}

// Change la position du monstre dans le labyrinthe
void move(Monster* monster, Cell new_position) {
    monster->current_position = new_position;
}

// Attaque le héros, mettant fin à la partie
void attack_hero(Monster* monster) {
    // TODO: implémenter la logique d'attaque
}
