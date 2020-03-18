#include <stdio.h>
#include <stdlib.h>
#include "polynome.h"

int main(){

    polynome_t *p1=malloc(sizeof(polynome_t)), *p2=malloc(sizeof(polynome_t)), *p3;

    readPoly(p1);
    printf(" \n First polynomial : ");
    displayPoly(p1);

    readPoly(p2);
    printf(" \n Second polynomial : ");
    displayPoly(p2);

    p3=addPoly(p1,p2);
    printf(" \n\n Resultant polynomial after addition : ");
    displayPoly(p3);
    printf("\n");

    return 0;
}