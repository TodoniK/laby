#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "labyrinthe.h"

int main() {

    int largeur = 17; 
    int hauteur = 17;
    char *labyrinthe;

    /* Allocation dynamique de la mémoire à la chaine de caractère correspondant à notre labyrinthe en fonction de la longueur et de la largeur choisie */
    labyrinthe = (char*)malloc(largeur * hauteur * sizeof(char));
   
    /* Affichage à l'écran du menu de choix pour l'utilisateur */
    int nombreChoisi;
    char entreeUtilisateur[100];

    while (1) {
        printf("\n\n-------------------------------------------\n");
        printf("Bienvenue dans le programme du labyrinthe.\n");
        printf("Que voulez-vous faire ?\n");
        printf("1. Generer le labyrinthe\n");
        printf("2. Afficher le labyrinthe\n");
        printf("3. Resoudre le labyrinthe\n");
        printf("4. Quitter\n");
        printf("-------------------------------------------\n\n\n");

        printf("Entrez votre choix : ");
        fgets(entreeUtilisateur, sizeof(entreeUtilisateur), stdin);
        if (sscanf(entreeUtilisateur, "%d", &nombreChoisi) != 1) { /* Vérification de saisie d'un entier et non d'un caractère alphabétique */
            printf("Saisie invalide. Veuillez entrer un nombre.\n");
            continue;
        }

        switch (nombreChoisi) {
            case 1:
                genererLaby(labyrinthe, largeur, hauteur);
                printf("\n-- LABYRINTHE GENERE --");
            break;

            case 2:
                printf("\n");
                afficherLaby(labyrinthe, largeur, hauteur);
            break;

            case 3:
                // Code pour résoudre le labyrinthe
            break;

            case 4:
                printf("Au revoir !\n\n");
                exit(0);

            default:
                printf("Choix invalide. Veuillez choisir un nombre entre 1 et 4.\n"); /* Vérification que l'entier saisi est compris entre 1 et 4 */
        }
    }

    /* Libération de la mémoire */
    free(labyrinthe);

    exit(EXIT_SUCCESS);
}
