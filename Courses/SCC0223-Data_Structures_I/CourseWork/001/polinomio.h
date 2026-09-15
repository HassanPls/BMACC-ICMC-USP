#ifndef POLINOMIO_H
#define POLINOMIO_H

#include <stdbool.h>
#include <stdint.h>

typedef struct polinomio_ POLINOMIO;

POLINOMIO *criar(void);
void destruir(POLINOMIO **p);

void inserir_ou_somar_termo(POLINOMIO *p, long long coef, long long grau);
void remover_termo(POLINOMIO *p, long long grau);
void remover_menor_grau(POLINOMIO *p);
void escala(POLINOMIO *p, long long c);

long long obter_coef(const POLINOMIO *p, long long grau);
long long obter_grau(const POLINOMIO *p);
bool eh_nulo(const POLINOMIO *p);

POLINOMIO *somar(const POLINOMIO *a, const POLINOMIO *b);
POLINOMIO *multiplicar(const POLINOMIO *a, const POLINOMIO *b);

void imprimir_canonica(const POLINOMIO *p); 
void imprimir_crescente(const POLINOMIO *p); 

#endif