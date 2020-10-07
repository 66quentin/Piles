#include "fonctions.h"

void test(){
	Pile *pile=creer_pile();
	Pile *pile2=creer_pile();
	pile2=empiler(pile2,1);
	
	if(estVide(pile)==1 && estVide(pile2)==0)
		printf("Fonction estVide() valide\n");
	else
		printf("Fonction estVide() invalide\n");
		
	if(hauteur(pile)==0 && hauteur(pile2)+1==hauteur(empiler(pile2,6)))
		printf("Fonction hauteur() valide\n");
	else
		printf("Fonction hauteur() invalide\n");

	if(estVide(empiler(pile,14))==0)
		printf("Fonction empiler() valide\n");
	else
		printf("Fonction empiler() invalide\n");

	if(sommet(empiler(pile2,1))==1)
		printf("Fonction sommet() valide\n");
	else
		printf("Fonction sommet() invalide\n");

	pile = depiler(empiler(pile2,3));
	if(sommet(pile)==sommet(pile2) && hauteur(pile)==hauteur(pile2))
		printf("Fonction depiler() valide\n");
	else
		printf("Fonction depiler() invalide\n");
		
	supprimer(pile);
	supprimer(pile2);
}

void hanoi(int n, Tour d, Tour f, Tour i){
	if (n == 1) { 
    		empiler(f.pile,sommet(d.pile));
    		depiler(d.pile);
		printf("Disque 1 déplacé de %s à %s\n", d.nom, f.nom); 
        return; 
    	} 
    	hanoi(n-1, d, i, f);
	printf("Disque %d déplacé de %s à %s\n", n, d.nom, f.nom); 
    	empiler(f.pile,sommet(d.pile));
    	depiler(d.pile);  
	hanoi(n-1, i, f, d); 
} 
