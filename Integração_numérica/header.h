#ifndef HERDER_H_INCLUDED
#define HERDER_H_INCLUDED

// função para fazer a diferença de um vetor
float* diff(float *v, int t);

// cria intervalos [a,b]
float* intervalo(float a, float b, int n);


// calcula a integral a esquerda
float integral_esq(float *f, float a, float b, int n);

// calcula a integral a direita
float integral_dir(float *f, float a, float b, int n);

// calcula a integral ao ponto médio
float integral_pt_med(float *f, float a,float b, int n);

// calcula a integral com trapézio
float integral_trap(float *f, float a, float b, int n);

// calcula a integral com a regra 1_3 de Simpson
float integral_1_3_simp(float *f, float a, float b, int n);

// calcula a integral com a regra 3/8 de Simpson
float integral_3_8_simp(float *f, float a, float b, int n);

#endif // HERDER_H_INCLUDED
