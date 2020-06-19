#include <stdio.h>
#include <stdlib.h>
#include "polynome.h"

int main(){

    polynome_t *p1=malloc(sizeof(polynome_t)), *p2=malloc(sizeof(polynome_t)), *p3, *p4, *pd;

    readPoly(p1);
    printf(" \n First polynomial : ");
    displayPoly(p1);

    readPoly(p2);
    printf(" \n Second polynomial : ");
    displayPoly(p2);

    pd=derivatePoly(p1);
    printf(" \n\n Resultant polynomial after derivate : ");
    displayPoly(pd);
    printf("\n");

    p3=addPoly(p1,p2);
    printf(" \n\n Resultant polynomial after addition : ");
    displayPoly(p3);
    printf("\n");
    
    p4=multiplyPoly(p1,p2);
    printf(" \n\n Resultant polynomial after multiplication : ");
    displayPoly(p4);
    printf("\n");

    return 0;
}
