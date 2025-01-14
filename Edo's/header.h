#ifndef HERDER_H_INCLUDED
#define HERDER_H_INCLUDED

// Funções
extern double funcao_1(double x, double y);


// cria intervalos [a,b]
float* intervalo_com_h(float a, float b, float h);

// Resolve EDO's pelo método de Euler
float *metodo_euler(double (funcao(double, double)), float a, float b, float h, float x, float y);

#endif // HERDER_H_INCLUDED
