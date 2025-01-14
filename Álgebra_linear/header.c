#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"

// Cria intervalos [a,b]

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

// Resolve sistemas diagonalizados
float *sol_triangular(float **A, float *b, int n){
	float *v, soma;
	v = (float*)malloc(n*sizeof(float));
	
	int i, j;
	for(i=n-1; i>=0; i=i-1){
		soma = 0;
		for(j=i+1; j<n; j++){
			soma = soma + A[i][j]*v[j];
		}
        	v[i] = (b[i] - soma)/A[i][i];
        }
	return v;
 }
 
 // Aumenta a matriz
float **matriz_aumentada(float **A, float *b, int n){
	float **M;
	int i,j;
	
	M =(float **)malloc(n * sizeof(float *));
	for(i=0; i<n; i++){
		M[i] = (float *)malloc((n+1)* sizeof(float *));
	}

	for(i=0; i<n; i++){
		for(j=0; j<n+1; j++){
			if(j==n){
				M[i][j] = b[i];
			}
			else{
				M[i][j]=A[i][j];
			}
		}
	}
	return M;
}


 // Triangularia a matriz
float **matriz_triangulariza(float **A, float *b, int n){

	int i,j,k, z=0;
	float **W, t, **M;
	
	W =(float **)malloc(n * sizeof(float *));
	for(i=0; i<n; i++){
		W[i] = (float *)malloc((n+1)* sizeof(float *));
	}
	
	M =(float **)malloc(n * sizeof(float *));
	for(i=0; i<n; i++){
		M[i] = (float *)malloc((n+1)* sizeof(float *));
	}
	
	M = matriz_aumentada(A, b, n);
	
	for(i=0; i<n+1; i++){
	W[0][i]=M[0][i];
	}

	for(j=0;j<n; j++){
		for(i=j+1; i<n; i++){
			if(z<n-1){
				t = M[i][j] / M[j][j];
				for(k=0; k<n+1; k++){
	        			W[i][k] = M[i][k] - t * M[j][k];
				}
        			z=z+1;
        		}
			else{
			        t = W[i][j] / W[j][j];
				for(k=0; k<n+1; k++){
					W[i][k] = W[i][k] - t * W[j][k];
				}
			}
		}
	}
	return W;
  
}


// Resolve sistemas
float *sol_geral(float **A, float *b, int n){

	int i,j,k, z=0;
	float *x, **M;
	
	x = (float *)malloc(n * sizeof(float *));
	
	M = (float **)malloc(n * sizeof(float *));
	for(i=0; i<n; i++){
		M[i] = (float *)malloc((n+1)* sizeof(float *));
	}

	M = matriz_triangulariza(A, b, n);

  	for(i=0; i<n; i++){
		for(j=0; j<n+1; j++){
			if(j==n){
			b[i]=M[i][j];
			}
			else{
			A[i][j]=M[i][j];
			}
		}
	}
  	
		x = sol_triangular(A, b, n);
	
	return x;
}	
	
// Escalona matrizes
float **matriz_escalonada(float **A, int n){

	int i, j, k;
	float **M;
	
	M = (float **)malloc(n * sizeof(float *));
	for(i=0; i<n; i++){
		M[i] = (float *)malloc((n+1)* sizeof(float *));
	}
	
	for(i=0; i<n; i++){

		for(j=0; j<n; j++){
			M[i][j] = A[i][j];
		}
	}
	
	for(k=0; k<n; k++){

	for(j=0; j<n; j++){
		M[k][j] = M[k][j]/M[k][k];
	}
	
		for(i=0; i<n; i++){
			if(i!= k){
				for(j=0; j<n; j++){
					M[i][j] = M[i][j] - M[i][k] * M[k][j];
				}
			}
		}
	}
	return M;
}

//Aproximação por mínimos quadrados 
float *aproxima_linear(float *x, float *y, int n, int p){

	int i,j;
	float soma1=0, soma2=0, soma3=0, soma4=0, soma5=0, soma6=0, soma7=0;
	
	if(p!=2 && p!=3){
		printf("\n\nCódigo foi somente adaptado para funções lineares e quadráticas, ou seja, 'p' é '2' ou '3'\n\n");
		return NULL;
	}
	
	float *b,*w,**A;
	b =(float *)malloc(p * sizeof(float *));
	w = (float *)malloc(p * sizeof(float *));
	A =(float **)malloc(p * sizeof(float *));
	for(i=0; i<p; i++){
		A[i] = (float *)malloc(p* sizeof(float *));
	}
	
	
	//Linear
	if(p==2){
		for(i=0;i<n;i++){
			soma1 = soma1 +x[i]*x[i];
			soma2 = soma2 + x[i];
			soma3 = soma3 + x[i]*y[i];
			soma4 = soma4 + y[i];
		}
	
		A[0][0]=soma1; A[0][1]=soma2;
		A[1][0]=soma2; A[1][1]=n;
		
		b[0]=soma3; b[1]=soma4;
	}
	
	//Quadrática
	else if(p==3){
		for(i=0;i<n;i++){
			soma1 = soma1 + x[i]*x[i]*x[i]*x[i];
			soma2 = soma2 + x[i]*x[i]*x[i];
			soma3 = soma3 + x[i]*x[i];
			soma4 = soma4 + x[i];
			soma5 = soma5 + y[i]*x[i]*x[i];
			soma6 = soma6 + y[i]*x[i];
			soma7 = soma7 + y[i];
		}
			
		A[0][0]=soma1; A[0][1]=soma2; A[0][2]=soma3;
		A[1][0]=soma2; A[1][1]=soma3; A[1][2]=soma4;
		A[2][0]=soma3; A[2][1]=soma4; A[2][2]=n;

		b[0] = soma5; b[1]=soma6; b[2]=soma7; 
	}
	
	w=sol_geral(A, b, p);
	return w;
}


	
