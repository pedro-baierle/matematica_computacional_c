#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"

#define pi 3.1415

int main() {

	int i;
	float dxi20[20], dxi40[40], *xi20, *xi40, s20[20], s40[40], c40[40];
	float *t, *t2;
	
// Intervalos

	xi20 = intervalo(0, 2*pi, 20);
	xi40 = intervalo(0, 2*pi, 40);

// Senos e cossenos

	for(i=0;i<20;i++){
		s20[i]=sin(xi20[i]);
	}
	
	for(i=0;i<40;i++){
		s40[i]=sin(xi40[i]);
		c40[i]=cos(xi40[i]);
	}

// Derivadas numéricas em 20 pontos

	t = diff(s20,20);
	t2= diff(xi20,20);
	
	for(i=0;i<20;i++){
	
	dxi20[i] = t[i]/t2[i] ;

	}
	free(t);
	free(t2);
	
// Derivadas numéricas em 40 pontos

	t = diff(s40,40);
	t2= diff(xi40,40);
	
	for(i=0;i<40;i++){
	
	dxi40[i] = t[i]/t2[i] ;

	}


float erro20, erro40;

	for(i=0; i<20; i++){
		erro20 = erro20 + fabs(c40[i] - dxi20[i]);
	}
	erro20=erro20/20 ;
	
	for(i=0; i<40; i++){
		erro40 = erro40 + fabs(c40[i] - dxi40[i]);
	}
	erro40=erro40/40 ;
	
	printf("\t Erro de 20 pontos: %f\n\t Erro de 40 pontos: %f \n", erro20, erro40);



/*
// Gráfico

	FILE *gnuplotPipe = popen("gnuplot -persistent", "w");

	fprintf(gnuplotPipe, "set title 'Derivadas'\n");  // Título do gráfico (opcional)


// Plotando o primeiro conjunto de pontos (20 pontos)

	fprintf(gnuplotPipe, "plot '-' title 'Derivada de 20 pontos' with lines lc rgb 'red'\n");
	for (i=0; i<20; i++) {
	fprintf(gnuplotPipe, "%lf %lf\n", xi20[i], dxi20[i]);
	}
	fprintf(gnuplotPipe, "\n");

// Plotando o segundo conjunto de pontos (40 pontos)

	fprintf(gnuplotPipe, "plot '-' title 'Derivada de 20 pontos' with lines lc rgb 'blue'\n");
	for (i=0; i<40; i++) {
    	fprintf(gnuplotPipe, "%lf %lf\n", xi40[i], dxi40[i]);
	}
	fprintf(gnuplotPipe, "\n");

// Plotando o segundo conjunto de pontos (40 pontos)

	fprintf(gnuplotPipe, "plot '-' title 'Exata' with lines lc rgb 'green'\n");
	for (i=0; i<40; i++) {
	    fprintf(gnuplotPipe, "%lf %lf\n", xi40[i], c40[i]);
	}


	fprintf(gnuplotPipe, "e\n");
	fflush(gnuplotPipe);
*/
	
	free(t);
	free(t2);
	free(xi20);
	free(xi40);
	
    return 0;
}

