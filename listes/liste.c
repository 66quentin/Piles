#include "fonctions.h"

Pile* creer_pile(){
	Pile *pile = malloc(sizeof(*pile));
	Element *element = malloc(sizeof(*element));

	if (pile == NULL || element == NULL)
		exit(EXIT_FAILURE);

	return pile;
}
		

Pile* empiler(Pile *pile, int i){
	Element *nouveau = malloc(sizeof(*nouveau));
    	if (nouveau == NULL)
    		exit(EXIT_FAILURE);
    	if(estVide(pile)){
    		nouveau->nombre = i;
		nouveau->suivant = NULL;
		pile->premier = nouveau;
	}else{
		nouveau->nombre = i;
    		nouveau->suivant = pile->premier;
    		pile->premier = nouveau;
    	}
	return pile;
}

Pile* depiler(Pile* pile){
	if (pile == NULL)
        	exit(EXIT_FAILURE);

	if (pile->premier != NULL){
		Element *aSupprimer = pile->premier;
		pile->premier = pile->premier->suivant;
		free(aSupprimer);
	}
	return pile;
}

int sommet(Pile* pile){
	if(pile->premier!=NULL)
		return pile->premier->nombre;
	else{
		printf("Erreur sommet: pile vide\n");
		exit(EXIT_FAILURE);
	}
}

int hauteur(Pile* pile){
	int i=0;
	Element *actuel = pile->premier;

	while (actuel != NULL){
        	i++;
        	actuel = actuel->suivant;
    	}
    	return i;
}

_Bool estVide(Pile *pile){
	if(pile->premier==NULL)
		return 1;
	return 0;
}

void afficher_pile(Pile* pile){
	if (pile == NULL)
		exit(EXIT_FAILURE);

	Element *actuel = pile->premier;

	while (actuel != NULL){
        	printf("%d -> ", actuel->nombre);
        	actuel = actuel->suivant;
    	}
    	printf("NULL\n");
}

void supprimer(Pile *pile){
    if (pile == NULL){
    	printf("Erreur suppression pile\n");
        exit(EXIT_FAILURE);
    }

    if (pile->premier != NULL){
        Element *aSupprimer = pile->premier;
        pile->premier = pile->premier->suivant;
        free(aSupprimer);
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
		Tour depart;
		depart.pile=creer_pile();
		depart.nom="Tour initiale";
	
		for(i=4;i>0;i--)
			depart.pile=empiler(depart.pile,i);
		
		Tour intermediaire;
		intermediaire.pile=creer_pile();
		intermediaire.nom="Tour intermediaire";
	
	
		Tour final;
		final.pile=creer_pile();
		final.nom="Tour finale";
		
		printf("Il y a %d disques\n",hauteur(depart.pile));
		hanoi(hauteur(depart.pile),depart,final,intermediaire);
		supprimer(depart.pile);
		supprimer(intermediaire.pile);
		supprimer(final.pile);
	}
	return 0;
}




