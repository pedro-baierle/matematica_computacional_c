#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"

float* diff(float *v, int t) {

	int i=0;
	float *r = (float*)malloc((t)*sizeof(float));


	for (i = 0; i<t; i++) {
		r[i] = v[i + 1] - v[i];
    }

    return r;
}




float* intervalo(int a, int b, int n){

	float t, y;
	int i=0;
	float *v = (float*)malloc(n*sizeof(float));
	

	y = (b-a);
	
	for(t=a; t<=b; t= t + y/n){
		v[i]=t;
		i++;
		
	}
	
	return v;
}

// Faz a derivada
float derivada(float(*funcao)(float), int a, int b, int n){
	
	float x*, *t, *t2, f[n], *d ;
	int i;
	
	x = intervalo(a, b, n);
	
	for(i=0;i<n;i++){
		f[i] = funcao(x[i]);
	}
	
	d = (float*)malloc((n - 1) * sizeof(float));
	t  = diff(f,n);
	t2 = diff(x,n);
	
	for(i=0;i<n;i++){
		d = t[i] / t2[i];
	}
	
	free(x);
	free(t);
	free(t2);
	
	return d;
}
