#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"
#define pi 3.14159265


float funcao(float x){
	return log(x+9);
}


void solucao_sistema_diag(){
	int i,j,k, l=4,c=4;
	float *b, *x;
	b =(float *)malloc(l * sizeof(float *));
	float **A;
	A =(float **)malloc(c * sizeof(float *));
	for(i=0; i<c; i++){
		A[i] = (float *)malloc(l * sizeof(float *));
	}
	float A_num[] = {-2, 3, -1, 1,0, -2, 4, 5, 0, 0, 1, 4, 0, 0, 0, 3};
	float b_num[] = {2,-3, 1, 2};
	k=0;
	for(i=0; i<l; i++){
		for(j=0; j<c; j++){
			A[i][j]=A_num[k];
			k++;
		}
	}
	for(i=0; i<l; i++){
			b[i]=b_num[i];
		}
		
	printf("\nSistema:\n\t A * X = b \n\n");
	printf("Matriz A:");
	for(i=0; i<l; i++){
		printf("\n\t");
		for(j=0; j<c; j++){
			printf("\t%.2f ", A[i][j]);
		}
	}
	printf("\nVetor b:\n\t");
	for(i=0; i<l; i++){
		printf("%.2f; ", b[i]);
	}
	x = sol_triangular(A, b, 4);
	printf("\n\nVetor solução X: \n\t"); 
	for(i=0; i<4; i++){
		printf("%.2f; ", x[i]);
	}
	printf("\n\n");	
	
	
	free(b); free(x); for(i=0;i<l;i++){free(A[i]);} free(A);
}




void solucao_sistema(){
	int i,j, k,l=4,c=4;
	float *b, *x;
	b =(float *)malloc(c * sizeof(float *));
	float **A;
	
	A =(float **)malloc(c * sizeof(float *));
	for(i=0; i<c; i++){
		A[i] = (float *)malloc(l * sizeof(float *));
	}
	float A_num[] = {-2, 3, -1, 1,5, -2, 4, 5, 3, 8, 1, 4, 1, 5, 9, 3};
	float b_num[] = {2,-3, 1, 2};
	k=0;
	for(i=0; i<l; i++){
		for(j=0; j<c; j++){
			A[i][j]=A_num[k];
			k++;
		}
	}
	for(i=0; i<l; i++){
			b[i]=b_num[i];
		}
	float **M;
	
	M =(float **)malloc(c * sizeof(float *));
	for(i=0; i<c; i++){
		M[i] = (float *)malloc(l+1 * sizeof(float *));
	}

	printf("Matriz A:");
	for(i=0; i<l; i++){
		printf("\n\t");
		for(j=0; j<c; j++){
			printf("\t%.2f ", A[i][j]);
		}
	}
	
	printf("\n\nVetor b:\t");
	for(i=0; i<l; i++){
		printf("%.2f; ", b[i]);
	}
	
	M=matriz_aumentada(A,b,4);
	printf("\n\nMatriz aumentada:");
	for(i=0; i<l; i++){
		printf("\n\t");
		for(j=0; j<c+1; j++){
			printf("\t%.2f ", M[i][j]);
		}
	}
	
	M = matriz_triangulariza(A,b,4);
	printf("\n\nMatriz aumentada triangulartizada:");
	for(i=0; i<l; i++){
		printf("\n\t");
		for(j=0; j<c+1; j++){
			printf("\t%.2f ", M[i][j]);
		}
	}
	
	x = sol_geral(A, b, 4);
	printf("\n\nVetor solução X: \n\t"); 
	for(i=0; i<4; i++){
		printf("%.2f; ", x[i]);
	}
	


	float **R;
	
	R =(float **)malloc(3 * sizeof(float *));
	for(i=0; i<c; i++){
		R[i] = (float *)malloc(4 * sizeof(float *));
	}




	k=7;
	for(i=0; i<3; i++){
		for(j=0; j<4; j++){
			R[i][i]=k+5*k+2;
			k++;
		}
	}
	
	
	
	M = matriz_escalonada(R,3);
	printf("\n\nMatriz A escalonada:");
	for(i=0; i<l; i++){
		printf("\n\t");
		for(j=0; j<c+1; j++){
			printf("\t%.2f ", M[i][j]);
		}
	}

	free(b); free(x); for(i=0;i<l;i++){free(A[i]);} free(A);
	printf("\n\n");
}


void interpolação_polinomial(){
	
	int i, j, n;
	
	float *r1, *r2, *x, *y;
	
	n=22;
	
	x =(float *)malloc(n * sizeof(float *));
	
	y =(float *)malloc(n * sizeof(float *));
	
	r1 =(float *)malloc(2 * sizeof(float *));
	
	r2 =(float *)malloc(3 * sizeof(float *));

	float x_num[]={1.12, 1.23, 1.28, 1.34, 1.36, 1.39, 1.44, 1.45, 1.47, 1.56, 1.58, 1.61, 1.63, 1.64, 1.68, 1.69, 1.74, 1.79, 1.80, 1.83, 1.87, 1.95};
	float y_num[]={2.86, 2.71, 2.45, 2.32, 2.22, 2.29, 2.02, 2.37, 2.43, 2.12, 2.33, 2.04, 2.19, 2.37, 2.38, 2.15, 2.28, 2.61, 2.75, 2.89, 2.15, 2.49};
	
	for(i=0; i<n;i++){
		x[i]=x_num[i];
		y[i]=y_num[i];
		printf("Ponto: (%.2f, %.2f);\n", x[i], y[i]);
	}	
	
	r1 = aproxima_linear(x, y, n, 2);
	
	r2 = aproxima_linear(x, y, n, 3);
	
	printf("\nVetor de coeficientes da função linear: (%f, %f) \n\n", r1[0], r1[1]);
	printf("\nVetor de coeficientes da função quadrática: (%f, %f, %f) \n\n", r2[0], r2[1], r2[2]);
	
	r2 = aproxima_linear(x, y, n, 4);
	
	free(r1); free(r2); free(x); free(y);
	printf("\n\n");
}

void main(){
interpolação_polinomial();
}
