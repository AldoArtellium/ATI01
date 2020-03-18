#include "polynome.h"
#include <stdio.h>

int readPoly (poly_t p[10]) {
	int t1;

	printf("\n\n Enter the total number of terms in the polynomial:");
	scanf("%d",&t1);

	printf("\n Enter the COEFFICIENT and EXPONENT in DESCENDING ORDER\n");
	for(int i = 0; i < t1; ++i) {
		printf("   Enter the Coefficient(%d): ",i+1);
		scanf("%d", &p[i].coeff);
		printf("      Enter the exponent(%d): ",i+1);
		scanf("%d", &p[i].expo);        /* only statement in loop */
	}

	return(t1);
}

int addPoly (poly_t p1[10], poly_t p2[10], int t1, int t2, poly_t p3[10]) {
	int i = 0, j = 0, k = 0;

	while (i<t1 && j<t2) {
		if (p1[i].expo==p2[j].expo) {
			p3[k].coeff=p1[i].coeff + p2[j].coeff;
			p3[k].expo=p1[i].expo;

			i++; j++; k++;
		} else if (p1[i].expo>p2[j].expo) {
			p3[k].coeff=p1[i].coeff;
			p3[k].expo=p1[i].expo;

			i++; k++;
		} else {
			p3[k].coeff=p2[j].coeff;
			p3[k].expo=p2[j].expo;

			j++; k++;
		}
	}

	while (i<t1) {
		p3[k].coeff=p1[i].coeff;
		p3[k].expo=p1[i].expo;
		i++;
		k++;
	}

	while (j<t2) {
		p3[k].coeff=p2[j].coeff;
		p3[k].expo=p2[j].expo;
		j++;
		k++;
	}

	return k;
}



void displayPoly (poly_t p[10], int term) {
	for (int k = 0; k < term-1; k++) {
		printf("%d(x^%d)+",p[k].coeff,p[k].expo);
	}
	printf("%d(x^%d)",p[term-1].coeff,p[term-1].expo);
}