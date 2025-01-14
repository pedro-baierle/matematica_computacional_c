#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"


// função para fazer a diferença de um vetor

float* diff(float *v, int t) {

	int i=0;
	float *r = (float*)malloc((t)*sizeof(float));

	for (i = 0; i<t; i++) {
		r[i] = v[i + 1] - v[i];
	}

	return r;
}


// cria intervalos [a,b]

float* intervalo(float a, float b, int n){

	float t=a, y;
	int i;
	float *v = (float*)malloc(n*sizeof(float));
	
	
	y = (b-a)/(n-1);
	
	for(i=0; i < n ; i++){
		v[i]=t;
		t = t + y;
	}
	
	return v;
}


// calcula a integral a esquerda

float integral_esq(float *f, float a, float b, int n){

	float h, integral=0;
	
	h = fabs(b-a)/n;
	
	for(int i=0; i<n; i++){
		integral = integral + f[i]*h;
	}
	
	return integral;
}


// calcula a integral a direita

float integral_dir(float *f, float a, float b, int n){

	float h, integral=0;
	h = fabs(b-a)/n;
	
	for(int i=1; i<n; i++){
		integral = integral + f[i]*h;
	}
	
	return integral;
}


// calcula a integral ao ponto médio

float integral_pt_med(float *f, float a, float b, int n){
	
	int i;
	float h, integral=0;
	h = fabs(b-a)/n;
	
	float *f_med;
	f_med = (float*)malloc((n-1)*sizeof(float));
	
	for(i=0; i<n-1; i++){
		f_med[i] = (f[i]+f[i+1])/2;
	}
	
	
	for(int i=0; i<n-1; i++){
		integral = integral + f_med[i]*h;
	}
	
	free(f_med);
	return integral;
}


// calcula a integral com trapézio

float integral_trap(float *f, float a, float b, int n){
	
	int i;
	float h, integral=0;
	h = fabs(b-a)/n;
	
	
	for(int i=0; i<n-1; i++){
		integral = integral + (f[i]+f[i+1])*h/2;
	}
	
	return integral;
}

// calcula a integral com a regra 1_3 de Simpson

float integral_1_3_simp(float *f, float a, float b, int n){

	int i;
	float h, integral=0;

	h = fabs(b-a)/n;

	if(n%2 !=0){
		n=n+1;
		printf("\n Para a regra 1/3 de Simpson, 'n' precisa ser par, então n=%d\n", n);
	}
		

	integral = f[0] + f[n];

	for (i = 1; i < n; i++) {
		if (i % 2 == 0) {
			integral = integral + 2 * f[i];
		} 
		else {
			integral = integral + 4 * f[i];
		}
	}

	integral = integral* h/3;

	return integral;
}

// calcula a integral com a regra 3/8 de Simpson

float integral_3_8_simp(float *f, float a, float b, int n){

	int i;
	float h, integral=0;

	h = fabs(b-a)/n;

	integral = f[0] + f[n];

	if(n%3 != 0){
		for(i=1; i>0; i++){
			if((n+i)%3==0){
				n=n+i;
				printf("\n Para a regra 3/8 de Simpson, 'n' precisa ser múltiplo de 3, então assumimos n=%d\n", n);
				break;
			}
			
		}
	}
	
	for (i = 1; i < n; i++) {
		if (i % 3 == 0) {
			integral = integral + 2 * f[i];
		} 
		else {
			integral = integral + 3 * f[i];
		}
	}

	integral = integral* 3*h/8;

	return integral;
}

