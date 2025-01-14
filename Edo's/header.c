#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"

// Cria intervalos com passo definido
float *intervalo_com_h(float a, float b, float h){

	int i, n;
	n = 1 + fabs(b-a)/h;

	
	float *v = (float*)malloc((n)*sizeof(float));

	for(i=0; i<n; i++){
		v[i]=a;
		a=a+h;
	}
	return v;
}

// Resolve EDO's pelo método de Euler
float *metodo_euler(double (funcao(double, double)), float a, float b, float h, float x, float y){
	float *v;
	int i, n;
	n = 1 + fabs(b-a)/h;

	float *s = (float*)malloc(n*sizeof(float));
	s[0]=y;
	
	
	v=intervalo_com_h(a, b, h);
	
	for(i=0; i<n; i++){
		s[i+1]=s[i]+funcao(v[i], s[i])*h;
	}
	
	free(v);
	return s;
}


