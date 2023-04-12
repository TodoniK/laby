#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "labyrinthe.h"

int getValeurCase(Labyrinthe lab, int x, int y){
   return lab.grille[y * lab.largeur + x];
}

void setValeurCase(Labyrinthe lab, int x, int y, int nouvelleValeur){
   lab.grille[y * lab.largeur + x] = nouvelleValeur;
}

// Correspondance avec typedef enum {COULOIR,MUR,NORD,SUD,EST,OUEST,MAX} enumCaractere (labyrinthe.h)
char * caracteresAffiche[MAX] = {"  ","██","↑↑","↓↓","→→","←←"};

void afficherLaby(Labyrinthe lab){

   /* On parcourt tout le labyrinthe et on affiche les cases */   
   for(int y = 0; y < lab.hauteur; y++) {
      for(int x = 0; x < lab.largeur; x++) {

         if(lab.resolu != 0){
            printf("%s",caracteresAffiche[getValeurCase(lab,x,y)]);
         } else {
            if(getValeurCase(lab,x,y) == MUR){
               printf("%s",caracteresAffiche[MUR]);
            } else {
               printf("%s",caracteresAffiche[COULOIR]);
            }
         }
      }
      printf("\n");
   }

}

void creuserLaby(Labyrinthe lab, int x, int y){

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

      if(xCaseDevant > 0 && xCaseDevant < lab.largeur && yCaseDevant > 0 && yCaseDevant < lab.hauteur /* On vérifie que la case devant notre case actuelle n'est pas en dehors des murs du labyrinthe */
         && getValeurCase(lab,xCaseDerriere,yCaseDerriere) == MUR && getValeurCase(lab,xCaseDevant,yCaseDevant) == MUR){ /* On vérifie que les deux cases adjacentes sont des murs */
         setValeurCase(lab,xCaseDerriere,yCaseDerriere,getDirectionOpposee(direction)); /* Si oui, on creuse et on place la flèche */
         setValeurCase(lab,xCaseDevant,yCaseDevant,getDirectionOpposee(direction));
         x = xCaseDevant; y = yCaseDevant;
         direction = rand() % 4;
         compteur = 0;
      } else {
         direction = (direction + 1) % 4; /* Si non, on change de direction */
         compteur += 1;
      }
   }
}

void genererLaby(Labyrinthe lab){
   
   /* On commence par remplir le labyrinthe de murs */
   for(int x = 0; x < lab.largeur * lab.hauteur; x++) {
      setValeurCase(lab,x,0,MUR);
   }

   /* Ajout de la case pour éviter l'ilôt du début */
   setValeurCase(lab,1,1,NORD);

   /* On met en place le noyeau de l'aléatoire dans le programme */
   srand(time(0));

   /* Pour chaque case, on va appeler la fonction creuserLaby qui reprend l'algo de reverse backtracking dans lequel 
      on va regarder si les quatres cases autour de la case courante sont creusables */
   for(int y = 1; y < lab.hauteur; y += 2) {
      for(int x = 1; x < lab.largeur; x += 2) {
         creuserLaby(lab, x, y);
      }
   }

   /* Ajouter une entrée dans le labyrinthe (ici deuxième case en haut à gauche) */
   setValeurCase(lab,lab.xEntree,lab.yEntree,NORD);
}

int getDirectionOpposee(int directionActuelle){
   switch (directionActuelle)
   {
      case 0 :
         return OUEST;
      break;

      case 1 :
         return NORD;
      break;

      case 2 :
         return EST;
      break;
      
      default:
         return SUD;
      break;
   }
}