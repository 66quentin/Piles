#include <stdio.h>
#include <stdlib.h>


/*---Structures propres aux listes----*/
typedef struct Element Element;
struct Element
{
    int nombre;
    Element *suivant;
};

typedef struct Pile {
    Element *premier;
} Pile;
/*------------------------------------*/

Pile* creer_pile();
Pile* empiler(Pile* pile, int i);
Pile* depiler(Pile* pile);
int sommet(Pile* pile);
int hauteur(Pile* pile);
_Bool estVide(Pile* pile);
void afficher_pile(Pile* pile);
void supprimer(Pile *pile);
