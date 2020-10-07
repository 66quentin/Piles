#include "fonctions.h"

void test(){
	Pile pile=creer_pile();
	Pile pile2=creer_pile();
	pile2=empiler(pile2,1);

	if(estVide(pile)==1 && estVide(pile2)==0)
		printf("Fonction estVide() valide\n");
	else
		printf("Fonction estVide() invalide\n");

	if(estVide(empiler(pile,14))==0)
		printf("Fonction empiler() valide\n");
	else
		printf("Fonction empiler() invalide\n");

	if(hauteur(pile)==0 && hauteur(pile2)+1==hauteur(empiler(pile2,6)))
		printf("Fonction hauteur() valide\n");
	else
		printf("Fonction hauteur() invalide\n");

	if(sommet(empiler(pile2,1))==1)
		printf("Fonction sommet() valide\n");
	else
		printf("Fonction sommet() invalide\n");

	pile = depiler(empiler(pile2,3));
	if(sommet(pile)==sommet(pile2) && hauteur(pile)==hauteur(pile2))
		printf("Fonction depiler() valide\n");
	else
		printf("Fonction depiler() invalide\n");
}

void hanoi(int n, Tour *d, Tour *i, Tour *f){
	if (n == 1) { 
    		f->pile=empiler(f->pile,sommet(d->pile));
    		d->pile=depiler(d->pile);
		printf("Disque %d déplacé de %s à %s\n", n, d->nom, f->nom);
		return ;
    	}else{
	    	hanoi(n-1, d, f, i);
	    	f->pile=empiler(f->pile,sommet(d->pile));
	    	d->pile=depiler(d->pile);
		printf("Disque %d déplacé de %s à %s\n", n, d->nom, f->nom);   		
		hanoi(n-1, i, d, f); 
	}
} 
