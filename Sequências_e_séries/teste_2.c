#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pi 3.14159265

double funcao_1(double n){
	return cos(n);
}

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



double derivada(double (*funcao)(double), double x, int n){
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

float taylor_series(double (*funcao)(double), float a, float x, int n){
	double soma = 0;
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



void main(){

	float t1, e1, a1, x1;
	int n1, i;
	
	a1 = 0;
	x1 = 0.5;
	n1 = 2;

	float d, t;
	
	
	for(i=1;i<8; i++){
		d = derivada(funcao_1, 0, i);
		printf("Derivada[%d] = %f\n",i, d);
	}
	
	for(i=1;i<8; i++){
		t = taylor_series(funcao_1, a1, x1, i);
		printf("A sequencia de taylor com '%d' termos é: %f\n",i, t);
	}
}

