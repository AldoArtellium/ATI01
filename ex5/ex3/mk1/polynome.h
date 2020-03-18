#ifndef POLYNOME_H_
#define POLYNOME_H_

typedef poly_s
{
	int coeff;
	int expo;
} poly_t;

int readPoly(poly_t []);
int addPoly(poly_t [],poly_t [],int ,int ,poly_t []);
void displayPoly( poly_t [], int);

#endif