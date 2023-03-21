#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 15
#define HEIGHT 15

int grid[WIDTH][HEIGHT];

void print_maze(){
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if (grid[i][j] == 1) {
                printf("█");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void generate_maze() {
    // Initialize the grid with walls
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if (i == 0 || j == 0 || i == WIDTH-1 || j == HEIGHT-1) {
                grid[i][j] = 1; // Surround the maze with walls
            } else if (i % 2 == 0 && j % 2 == 0) {
                grid[i][j] = 1; // Mark the walls
            } else if (i % 2 == 1 && j % 2 == 0) {
                grid[i][j] = 0; // Clear the even rows
            } else {
                grid[i][j] = 1; // Mark the walls
            }
        }
    }

    // Dig odd columns
    for (int i = 1; i < WIDTH-1; i += 2) {
        for (int j = 1; j < HEIGHT-1; j++) {
            grid[i][j] = 0; // Dig the odd columns
        }
    }

    // Dig random cells in even columns
    srand(time(NULL)); // Seed the random number generator with the current time
    int num_digs = rand() % ((WIDTH/2-1)*(HEIGHT-2)); // Choose a random number of cells to dig
    for (int n = 0; n < num_digs; n++) {
        int i = rand() % (WIDTH/2-1) * 2 + 2; // Choose a random even column
        int j = rand() % (HEIGHT-2) + 1; // Choose a random row (excluding walls)
        if (grid[i][j] == 1) {
            grid[i][j] = 0; // Dig the cell
        }
    }

}

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

    generate_maze();
    print_maze();
    
    return 0;
}
