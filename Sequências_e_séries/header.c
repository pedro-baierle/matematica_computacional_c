#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"

// Cria intervalos [a,b]
float *intervalo(float a, float b, int n){

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


// Calcula fatorial
float fatorial(float n){
	float fatorial=1;
	int i;
	if(n>0){
		for(i=1; i<=n; i++){
			fatorial = fatorial * i;
		}
	}
	return fatorial;
}


// Calcula a derivada de ordem superior 
double derivada(double (*funcao)(double), float x, int n){
	double d, d_a;
	float h=0.01;
	double f_x = funcao(x);
    
	if (n == 1){
		d = (funcao(x + h) - f_x) / h; // certo
	}

	else if(n > 1){
		d_a = derivada(funcao, x, n - 1);
		d = (derivada(funcao, x+h, n - 1) - d_a)/h;

	}

	return d;

}



// analiza se a sequencia converge
float sequencia_convergente(float(*sequencia)(float), int n, float e){

	int i, j;
	
	float p[n], soma=0;
	
	for(i=0;i<n; i++){
		p[i]=sequencia(i);
	}
	
	for(i=1; i<11; i++){
		soma = soma + p[n-i];
	}
	soma = soma/10;
	
	if(soma < (p[n-1]+e) && soma > (p[n-1]-e)){
		printf("\n\n A sequência  converge para %f com pontos %d e erro %f\n\n", soma, n, e);
		return soma;
	}
	
	else{
		printf("\n\n A sequência não converge com %d pontos e erro %f\n\n", n, e);
		return 0;
	}

}

// analiza se a serie converge
float serie_convergente(float(*serie)(float), int n, float e){

	int i, j;
	
	float p[n], soma1=0, soma2=0;
	
	for(i=0;i<n; i++){
		p[i]=serie(i);
	}
	
	for(i=0; i<n; i++){
		soma1 = soma1 + p[i];

	}
	for(i=n-11; i<n; i++){
		soma2 = soma2 + p[i];

	}

	
	if(fabs(soma2) < e){
		printf("\n\n A serie  converge para %f com pontos %d e erro %f\n\n", soma1, n, e);
		return soma1;
	}
	
	else{
		printf("\n\n A serie não converge com %d pontos e erro %f\n\n", n, e);
		return 0;
	}

}


// Função para calcular a série de Taylor de f em torno de 'a' até 'n' termos
float taylor_series(double (*funcao)(double), float a, float x, int n){
	float soma = 0;
	double d, f;
	int i;
	
	for(i=0; i<n; i++){
        	f = fatorial(i);
		
		if(i==0){
			soma = soma + funcao(a) * pow(x-a, i)/f;
		}
		
		else{
			d = derivada(funcao, a, i);
			soma = soma + d * pow(x-a, i)/f ;
		}
	}
	
	return soma;
}



float fourier_series(double (*funcao)(double), float a, float x, int n){

}
