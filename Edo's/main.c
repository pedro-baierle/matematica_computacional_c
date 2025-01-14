#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"
#define pi 3.14159265

double funcao_1(double x, double y){
	return x-y+2;
}


void teste_metodo_euler(){

	float a,b,h,x,y, *s;
	int i, n;
	
	a=0;
	b=1;
	h=0.2;
	x=0;
	y=2;
	n = 1 + (b-a)/h;

	s = metodo_euler(funcao_1, a, b, h, x, y);
	
	for(i=0; i<n; i++){
		printf("s[%d] = %f\n", i, s[i]);
	}
	
}



void main(){
teste_metodo_euler();
};
