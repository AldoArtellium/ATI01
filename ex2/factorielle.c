#include "factorielle.h"
#include <stdio.h>

double factorielle_int(int a){
	double b = 1;
	for (int i = 1; i <= a; i++) {
		b *= i;
	}
	return b;
}

double factorielle_rec(int a){
  	if (a == 0) {
    	return 1;
  	} else {
    	return(a * factorielle_rec(a-1));
	}
}