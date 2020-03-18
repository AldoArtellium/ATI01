#include "polynome.h"
#include <stdio.h>
#include <stdlib.h>

void readPoly (polynome_t *p) {
	int degree = 0;

	printf("\n\n Enter the total number of terms in the polynomial:");
	scanf("%d",&degree);

	p->len = degree;

	printf("\n Enter the COEFFICIENT and EXPONENT in DESCENDING ORDER\n");
	for(int i = 0; i < degree; ++i) {
		printf("   Enter the Coefficient(%d): ",i+1);
		scanf("%d", &p->poly[i].coeff);
		printf("      Enter the exponent(%d): ",i+1);
		scanf("%d", &p->poly[i].expo);
	}
}

polynome_t *addPoly (polynome_t *p1, polynome_t *p2) {
	polynome_t *p3 = malloc(sizeof(polynome_t));
	int i = 0, j = 0, k = 0;
	printf("%d\n", p1->len);
	while (i < p1->len && j < p2->len) {
		if (p1->poly[i].expo == p2->poly[j].expo) {
			p3->poly[k].coeff = p1->poly[i].coeff + p2->poly[j].coeff;
			p3->poly[k].expo = p1->poly[i].expo;

			i++; j++; k++;
		} else if (p1->poly[i].expo > p2->poly[j].expo) {
			p3->poly[k].coeff = p1->poly[i].coeff;
			p3->poly[k].expo = p1->poly[i].expo;

			i++; k++;
		} else {
			p3->poly[k].coeff = p2->poly[j].coeff;
			p3->poly[k].expo = p2->poly[j].expo;

			j++; k++;
		}
	}

	while (i < p1->len) {
		p3->poly[k].coeff = p1->poly[i].coeff;
		p3->poly[k].expo = p1->poly[i].expo;

		i++; k++;
	}

	while (j < p2->len) {
		p3->poly[k].coeff = p2->poly[j].coeff;
		p3->poly[k].expo = p2->poly[j].expo;

		j++; k++;
	}

	p3->len = k;

	return p3;
}

void displayPoly (polynome_t *p) {
	for (int k = 0; k < p->len-1; k++) {
		printf("%d(x^%d)+", p->poly[k].coeff, p->poly[k].expo);
	}
	printf("%d(x^%d)", p->poly[p->len-1].coeff, p->poly[p->len-1].expo);
}