#include <stdio.h>
#include "Piles.h"

typedef struct tour {
	Pile pile;
	char* nom;
} Tour;
void test();
void hanoi(int n, Tour *d, Tour *f, Tour *i);
