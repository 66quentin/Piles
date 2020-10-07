#include "fonctions.h"

Pile creer_pile(){
	Pile pile;
	pile.i_sommet=-1;
	return pile;
}
		

Pile empiler(Pile pile, int i){
	if(pile.i_sommet < MAX){
		pile.i_sommet++;
		pile.tableau[pile.i_sommet]=i;
		return pile;
	}else{
		printf("Erreur empiler: pile pleine\n");
		exit(EXIT_FAILURE);
	}
}

Pile depiler(Pile pile){
	if(pile.i_sommet>-1){
		pile.i_sommet--;
		return pile;
	}else{
		printf("Erreur depiler: pile vide\n");
		exit(EXIT_FAILURE);
	}
}

int sommet(Pile pile){
	if(pile.i_sommet>=0)
		return pile.tableau[pile.i_sommet];
	else{
		printf("Erreur sommet: pile vide\n");
		exit(EXIT_FAILURE);
	}
}

int hauteur(Pile pile){
	return pile.i_sommet+1;
}

_Bool estVide(Pile pile){
	if(pile.i_sommet==-1)
		return 1;
	return 0;
}

void afficher_pile(Pile pile){
	if(pile.i_sommet>=-1){
		for(int i=0;i<=pile.i_sommet;i++)
			printf("[%d]",pile.tableau[i]);
		printf("\n");
	}else{
		printf("Erreur affichage: pile vide\n");
		exit(EXIT_FAILURE);
	}
}

int main (void){
	int choix;
	printf("Hanoï (0) ou tests unitaires (1) ? ");
	scanf("%d",&choix);
	if(choix==1)
		test();
	else if(choix==0){ 
		int i;	
		Tour *depart;
		depart=malloc(sizeof(Tour));
		depart->pile=creer_pile();
		depart->nom="Tour initiale";
		
		for(i=4;i>0;i--)
			depart->pile=empiler(depart->pile,i);
			
		Tour *intermediaire;
		intermediaire=malloc(sizeof(Tour));
		intermediaire->pile=creer_pile();
		intermediaire->nom="Tour intermediaire";
		
		
		Tour *final;

		final=malloc(sizeof(Tour));
		final->pile=creer_pile();
		final->nom="Tour finale";
		
		printf("Il y a %d disques\n",hauteur(depart->pile));
		hanoi(hauteur(depart->pile),depart,final,intermediaire);
	}
	return 0;
}





