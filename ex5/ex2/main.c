#include <stdio.h>
#include "factorielle.h"

int main() {
	int nbr;
	double fact_int, fact_rec;
	 
	printf("Entrez un nombre pour calculer sa factorielle\n");
	scanf("%d", &nbr);
	 
	if (nbr < 0) {
	    printf("La factorielle des entiers négatifs n'est pas définie.\n");
	} else {
	    fact_int = factorielle_int(nbr);
	    fact_rec = factorielle_rec(nbr);
	    printf("Itérative: %d! = %lf\n", nbr, fact_int);
	    printf("Récursive: %d! = %lf\n", nbr, fact_rec);
	}
	return 0;
}