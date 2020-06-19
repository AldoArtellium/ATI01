#include "polynome.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

polynome_t *derivatePoly (polynome_t *p1) {
	polynome_t *p2 = malloc(sizeof(polynome_t));

    for(int i = 0; i < p1->len; ++i){
        p2->poly[i].coeff=p1->poly[i].coeff*p1->poly[i].expo;
        p2->poly[i].expo=p1->poly[i].expo-1;
    }
    
    p2->len=p1->len;

    return p2;
}

int evaluatePoly (polynome_t *p1, int x) {
    int total = 0;
    for(int i = 0; i < p1->len; ++i){
        total += (p1->poly[i].coeff)*((int)pow(x,p1->poly[i].expo));
    }

    return total;
}

polynome_t *addPoly (polynome_t *p1, polynome_t *p2) {
	polynome_t *p3 = malloc(sizeof(polynome_t));
	int i = 0, j = 0, k = 0;
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

polynome_t *multiplyPoly(polynome_t *p1, polynome_t *p2)
{       
    polynome_t *p3 = malloc(sizeof(polynome_t));
    p3->len=p1->poly[0].expo+p2->poly[0].expo;

    for(int i = 0; i < p1->len; ++i){
        for(int j = 0; j < p2->len; ++i){
            p3->poly[i+j].expo = i+j;
            p3->poly[i+j].coeff += p1->poly[i].coeff * p2->poly[j].coeff;
        }
    }
    /*
    if(p1.expo > p2.expo)
        for(i=0; i <= p3.expo; i++){ 
            *(p3.coeff+i) = 0;
            for(j=0; j <= i; j++)
                *(p3.coeff+i) += *(p2.coeff+j) * (*(p1.coeff + (i-j)));
        }
    } else if(p2.expo > p1.expo){
        for(i=0; i <= p3.expo; i++) { 
            *(p3.coeff+i) = 0;
            for(j=0; j <= i; j++)
                *(p3.coeff+i) += *(p1.coeff+j) * (*(p2.coeff + (i-j)));
        }
    } else{ 
        for(i=0; i <= p3.expo; i++){
            *(p3.coeff+i) = 0;
            for(j=0; j <= i; j++){  
                *(p3.coeff+i) += *(p1.coeff+j) * (*(p2.coeff + (i-j)));
            }
        }
    }
    */
    return p3;
}

void displayPoly (polynome_t *p) {
	for (int k = 0; k < p->len-1; k++) {
		printf("%d(x^%d)+", p->poly[k].coeff, p->poly[k].expo);
	}
	printf("%d(x^%d)", p->poly[p->len-1].coeff, p->poly[p->len-1].expo);
}
