#ifndef HERDER_H_INCLUDED
#define HERDER_H_INCLUDED

// Declaração da sequencia em main.c
extern float sequencia_1(float n);
extern float sequencia_2(float n);

// Declaração da serie em main.c
extern float serie_1(float n);
extern float serie_2(float n);

// Declaração de funcao em main.c
extern double funcao_1(double n);
extern double funcao_2(double n);


// cria intervalos [a,b]
float* intervalo(float a, float b, int n);

// Calcula fatorial
float fatorial(float n);

// Calcula a derivada de ordem superior em um ponto
double derivada(double (*func)(double), float x, int n);

// analiza se a sequencia converge
float sequencia_convergente(float(*sequencia)(float), int n, float e);

// analiza se a serie converge
float serie_convergente(float(*serie)(float), int n, float e);

// Calcula a série de Taylor de 'funcao' em torno de 'a' do ponto 'x' , em 'n' termos
float taylor_series(double (*funcao)(double), float a, float x, int n);

// Calcula a série de Fourier de 'funcao' em torno de 'a' do ponto 'x' , em 'n' termos
float fourier_series(double (*funcao)(double), float a, float x, int n);

#endif // HERDER_H_INCLUDED
