#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"
#define pi 3.14159265


float funcao(float x){
	return log(x+9);
}


int main(){

	int i, j, n;
	float a,b, *xi, *f;
	
	n = 97;
	a = 1;
	b = 7;
	xi = intervalo(a,b,n);

	
	f = (float*)malloc((n)*sizeof(float));
	
	for(i=0; i<n;i++){
		f[i]= funcao(xi[i]);
	}
	
	
	float int_s, int_esq, int_dir, int_pt_med, int_trap, int_1_3_simp, int_3_8_simp;
	
	int_s = 15.335568625896038;
	
	int_esq = integral_esq(f, a, b, n);
	int_dir = integral_dir(f, a, b, n);
	int_pt_med = integral_pt_med(f, a, b,n);
	int_trap = integral_trap(f, a, b,n);
	int_1_3_simp = integral_1_3_simp(f,a,b,n);
	int_3_8_simp = integral_3_8_simp(f,a,b,n);
	
	
	printf("\n\n\n");
	printf("Integral simbólica: %.5f\n", int_s);
	printf("Integral a esquerda: %.5f\n", int_esq);
	printf("Integral a direita: %.5f\n", int_dir);	
	printf("Integral ao ponto médio: %.5f\n", int_pt_med);	
	printf("Integral ao trapézio: %.5f\n", int_trap);	
	printf("Integral a 1/3 de Simpson: %.5f\n", int_1_3_simp);	
	printf("Integral a 3/8 de Simpson: %.5f\n", int_3_8_simp);
	
	
	

	float erro_esq, erro_dir, erro_pt_med, erro_trap, erro_1_3_simp, erro_3_8_simp;
	
	erro_esq = fabs(int_s - int_esq);
	erro_dir = fabs(int_s - int_dir);
	erro_pt_med = fabs(int_s - int_pt_med);
	erro_trap = fabs(int_s - int_trap);
	erro_1_3_simp = fabs(int_s - int_1_3_simp);
	erro_3_8_simp = fabs(int_s - int_3_8_simp);
	
	printf("\n\n\n");
	printf("Erro da integral a esquerda: %.5f\n", erro_esq);
	printf("Erro da integral a direita: %.5f\n", erro_dir);	
	printf("Erro da integral ao ponto médio: %.5f\n", erro_pt_med);	
	printf("Erro da integral ao trapézio: %.5f\n", erro_trap);	
	printf("Erro da integral a 1/3 de Simpson: %.5f\n", erro_1_3_simp);
	printf("Erro da integral a 3/8 de Simpson: %.5f\n", erro_3_8_simp);
	
	free(xi);
	free(f);
	printf("\n\n\n");
	return 1;
}
