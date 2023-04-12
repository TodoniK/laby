#include <stdio.h>
#include <stdlib.h>
#include "labyrinthe.h"

int main() {

    Labyrinthe laby = {
        .xEntree = 1,
        .yEntree = 0,
        .hauteur = 39,
        .largeur = 39,
        .genere = 0,
        .resolu = 0,
        .grille = (char*)malloc(laby.largeur * laby.hauteur * sizeof(char)) /* Allocation dynamique de la mémoire à la chaine de caractère correspondant à notre labyrinthe en fonction de la longueur et de la largeur choisie */
    };
   
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
                genererLaby(laby);
                laby.genere = 1;
                laby.resolu = 0;
                printf("\n-- LABYRINTHE GENERE --\n");
            break;

            case 2:
                if(laby.genere != 0){
                    printf("\n");
                    afficherLaby(laby);
                } else {
                    printf("Veuillez generer le labyrinthe une premiere fois !\n"); /* Si le labyrinthe est à été généré on affiche sinon msg d'erreur */
                } 
            break;

            case 3:
                if(laby.genere != 0){
                    laby.resolu = 1;
                    printf("\n-- LABYRINTHE RESOLU --");
                } else {
                    printf("Veuillez generer le labyrinthe une premiere fois !\n"); /* Si le labyrinthe est à été généré on resout sinon msg d'erreur */
                } 
            break;

            case 4:
                printf("Au revoir !\n\n");
                exit(0);

            default:
                printf("Choix invalide. Veuillez choisir un nombre entre 1 et 4.\n"); /* Vérification que l'entier saisi est compris entre 1 et 4 */
        }
    }

    /* Libération de la mémoire */
    free(laby.grille);

    exit(EXIT_SUCCESS);
}
