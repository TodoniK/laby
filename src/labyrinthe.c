#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "labyrinthe.h"

void afficherLaby(const char *labyrinthe, int largeur, int hauteur){

   /* On parcourt tout le labyrinthe et on affiche les cases */   
   for(int y = 0; y < hauteur; y++) {
      for(int x = 0; x < largeur; x++) {
         switch(labyrinthe[y * largeur + x]) {
            case 1:  
               printf("██");  
               break;
         
            default: 
               printf("  ");  
               break;
         }
      }
      printf("\n");
   }

}

void creuserLaby(char *labyrinthe, int largeur, int hauteur, int x, int y){

   int xCaseDerriere, yCaseDerriere;
   int xCaseDevant, yCaseDevant;
   int dx, dy;
   int direction = rand() % 4; /* On prend un nombre aléatoire modulo 4 pour faire une rotation circulaire */
   int compteur = 0;

   while(compteur < 4) { /* Ici on fait une boucle qui va regarder les 4 directions autour de la case en x,y pour voir si des cases peuvent être creusées */
      
      dx = 0; dy = 0;
      
      switch(direction) { /* En fonction du nombre aléatoire généré, on affecte des valeurs aux coordonnées delta */
         case 0:  
            dx = 1;  
            break;
         
         case 1:  
            dy = 1;  
            break;

         case 2:  
            dx = -1; 
            break;
         
         default: 
            dy = -1; 
            break;
      }

      /* En fonction de l'affectation des delta, on obtient les coordonées des deux cases adjacentes (devant et derrière) de notre case actuelle qui est en x,y */
      xCaseDerriere = x + dx; 
      yCaseDerriere = y + dy;
      xCaseDevant = xCaseDerriere + dx;
      yCaseDevant = yCaseDerriere + dy;

      if(xCaseDevant > 0 && xCaseDevant < largeur && yCaseDevant > 0 && yCaseDevant < hauteur /* On vérifie que la case devant notre case actuelle n'est pas en dehors des murs du labyrinthe */
         && labyrinthe[yCaseDerriere * largeur + xCaseDerriere] == 1 && labyrinthe[yCaseDevant * largeur + xCaseDevant] == 1){ /* On vérifie que les deux cases adjacentes sont des murs */
         labyrinthe[yCaseDerriere * largeur + xCaseDerriere] = 0; /* Si oui, on creuse */
         labyrinthe[yCaseDevant * largeur + xCaseDevant] = 0;
         x = xCaseDevant; y = yCaseDevant;
         direction = rand() % 4;
         compteur = 0;
      } else {
         direction = (direction + 1) % 4; /* Si non, on change de direction */
         compteur += 1;
      }
   }
}

void genererLaby(char *labyrinthe, int largeur, int hauteur){

   /* On commence par remplir le labyrinthe de murs */
   for(int x = 0; x < largeur * hauteur; x++) {
      labyrinthe[x] = 1;
   }

   /* On met en place le noyeau de l'aléatoire dans le programme */
   srand(time(0));

   /* Pour chaque case, on va appeler la fonction creuserLaby qui reprend l'algo de reverse backtracking dans lequel 
      on va regarder si les quatres cases autour de la case courante sont creusables */
   for(int y = 1; y < hauteur; y += 2) {
      for(int x = 1; x < largeur; x += 2) {
         creuserLaby(labyrinthe, largeur, hauteur, x, y);
      }
   }

   /* Ajouter une entrée dans le labyrinthe (ici deuxième case en haut à gauche) */
   labyrinthe[0 * largeur + 1] = 0;

}