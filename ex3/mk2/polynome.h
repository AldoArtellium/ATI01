#ifndef POLYNOME_H_
#define POLYNOME_H_

typedef struct poly_s {
	int coeff;
	int expo;
} poly_t;

typedef struct polynome_s {
	poly_t poly[10];
	int len;
} polynome_t;

void readPoly(polynome_t*);
polynome_t *derivatePoly(polynome_t*);
int evaluatePoly(polynome_t*, int);
polynome_t *addPoly(polynome_t*, polynome_t*);
polynome_t *multiplyPoly(polynome_t*, polynome_t*);
void displayPoly(polynome_t*);

#endif
