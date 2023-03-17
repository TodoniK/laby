#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "cell.h"
#include <time.h>

#define WIDTH 20
#define HEIGHT 10

int main() {
   /*int choice;
   char input[100];

   while (1) {
      printf("\n\n-------------------------------------------\n");
      printf("Bienvenue dans le programme de labyrinthe.\n");
      printf("Que voulez-vous faire ?\n");
      printf("1. Générer et afficher un labyrinthe\n");
      printf("2. Parcourir un labyrinthe\n");
      printf("3. Résoudre un labyrinthe\n");
      printf("4. Quitter\n");
      printf("-------------------------------------------\n\n");

      printf("Entrez votre choix : ");
      fgets(input, sizeof(input), stdin);
      if (sscanf(input, "%d", &choice) != 1) {
          printf("Saisie invalide. Veuillez entrer un nombre.\n");
          continue;
      }

      switch (choice) {
         case 1:
            // Code pour générer un labyrinthe
            break;
         case 2:
            // Code pour afficher un labyrinthe
            break;
         case 3:
            // Code pour parcourir un labyrinthe
            break;
         case 4:
            printf("Au revoir !\n");
            exit(0);
         default:
            printf("Choix invalide. Veuillez choisir un nombre entre 1 et 6.\n");
      }
   }*/

   // Initialisation du générateur de nombres pseudo-aléatoires
    srand(time(NULL));

    enum cell maze[WIDTH][HEIGHT];

    // Initialisation de toutes les cases à "mur"
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            maze[i][j] = Wall;
        }
    }

    // Génération des couloirs (cases impaires)
    for (int i = 1; i < WIDTH; i += 2) {
        for (int j = 1; j < HEIGHT; j += 2) {
            maze[i][j] = Corridor;
        }
    }

    // Creusement de cases aléatoires
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if (maze[i][j] == Wall && rand() % 2 == 0) {
                maze[i][j] = Corridor;
            }
        }
    }

    // Affichage du labyrinthe
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (maze[j][i] == Wall) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
