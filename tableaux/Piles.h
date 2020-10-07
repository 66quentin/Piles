#include <stdio.h>
#include <stdlib.h>
#define MAX 10

/*---Structure propre aux tableaux----*/
typedef struct Pile {
	int tableau[MAX];
	int i_sommet;
} Pile;
/*------------------------------------*/

Pile creer_pile();
Pile empiler(Pile pile, int i);
Pile depiler(Pile pile);
int sommet(Pile pile);
int hauteur(Pile pile);
_Bool estVide(Pile pile);
void afficher_pile(Pile pile);
