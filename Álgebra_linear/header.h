#ifndef HERDER_H_INCLUDED
#define HERDER_H_INCLUDED


// cria intervalos [a,b]
float* intervalo(float a, float b, int n);

// Resolve sistemas diagonalizados
float *sol_triangular(float **A, float *b, int n);

// Cria matrizes aumentadas
float **matriz_aumentada(float **A, float *b, int n);

// Triangulariza matrizes
float **matriz_triangulariza(float **A, float *b, int n);


// Resolve sistemas
float *sol_geral(float **A, float *b, int n);

// Escalona matrizes
float **matriz_escalonada(float **A, int n);

//Aproximação por mínimos quadrados 
float *aproxima_linear(float *a, float *b, int n, int p);

#endif // HERDER_H_INCLUDED
