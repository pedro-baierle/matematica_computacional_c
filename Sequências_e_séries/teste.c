#include <stdio.h>
#include <math.h>

// Função para calcular o coeficiente binomial
int coeficiente_binomial(int n, int k) {
    if (k == 0 || k == n)
        return 1;
    return coeficiente_binomial(n - 1, k - 1) + coeficiente_binomial(n - 1, k);
}

// Função para calcular a k-ésima derivada usando diferenças finitas
long double k_esima_derivada(long double (*funcao)(long double), long double x, int k, long double h) {
    long double derivada = 0.0;
    int i, sinal;

    for (i = 0; i <= k; i++) {
        sinal = (i % 2 == 0) ? 1 : -1;
        derivada += sinal * coeficiente_binomial(k, i) * funcao(x + (k - 2 * i) * h);
    }

    derivada /= pow(h, k);
    
    return derivada/pow(2,k);
}

// Função de cosseno para teste
long double funcao_cosseno(long double x) {
    return cos(x); // Função cosseno
}

int main() {
    long double x = 0.0; // Ponto onde queremos calcular a derivada
    long double h = 0.01; // Tamanho do passo
    int k = 1; // Ordem da derivada
    
	for(k; k<10;k++){
		long double resultado = k_esima_derivada(funcao_cosseno, x, k, h);
 
		printf("A %d-ésima derivada de cos(x) em x = %.2Lf é %.6Lf\n", k, x, resultado);
	}

    return 0;
}



