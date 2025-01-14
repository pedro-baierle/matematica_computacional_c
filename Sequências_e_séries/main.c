#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"
#define pi 3.14159265


float sequencia_1(float n){
	return n/(2*n+1);
}
float sequencia_2(float n){
	return n/2;
}

float serie_1(float n){
	return 1/pow(2,n);
}

float serie_2(float n){
	return n;
}

double funcao_1(double n){
	return cos(n);
}

double funcao_2(double n){
	return log(n+1);
}

/////////////////////////////////

void teste_convergencia(){

	int i,j,k,n;
	float c1, c2, c3, c4, e;
	e=0.001;
	n=1000;	
	c1 = sequencia_convergente(sequencia_1, n, e);
	c2 = sequencia_convergente(sequencia_2, n, e);
	
	c3 = serie_convergente(serie_1, n, e);
	c4 = serie_convergente(serie_2, n, e);
	
}

void teste_taylor(){

	float a1, x1;
	int i;
	
	a1 = 0;
	x1 = 0.5;

	float d, t1, e1;
	
	for(i=1;i<7; i++){
		t1 = taylor_series(funcao_1, a1, x1, i);
		e1 = fabs(cos(x1)-t1);
		printf("\n\nO valor aproximado pela serie de taylor de 'cos(%.2f)' pelo ponto '%.2f' em '%d' termos é %f \n\n", x1, a1, i, t1);
		printf("O erro foi de %f\n\n", e1);
	}
	
	a1 = 0;
	x1 = 0.5;
	
	for(i=1;i<7; i++){
		t1 = taylor_series(funcao_2, a1, x1, i);
		e1 = fabs(log(x1+1)-t1);
		printf("\n\nO valor aproximado pela serie de taylor de 'log(%.2f+1)' pelo ponto '%.2f' em '%d' termos é %f \n\n", x1, a1, i, t1);
		printf("O erro foi de %f\n\n", e1);
	}
	
	
	
	
}

void main(){
teste_taylor();
};
