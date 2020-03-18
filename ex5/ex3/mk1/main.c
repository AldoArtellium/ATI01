#include <stdio.h>
#include "polynome.h"

int main(){

    poly_t p1[10],p2[10],p3[10];

    int t1,t2,t3;

    t1=readPoly(p1);
    printf(" \n First polynomial : ");
    displayPoly(p1,t1);

    t2=readPoly(p2);
    printf(" \n Second polynomial : ");
    displayPoly(p2,t2);

    t3=addPoly(p1,p2,t1,t2,p3);
    printf(" \n\n Resultant polynomial after addition : ");
    displayPoly(p3,t3);
    printf("\n");

    return 0;
}