#ifndef RACIONAL_H
#define RACIONAL_H

typedef struct racional RACIONAL;

RACIONAL *criar(int num, int den);
void limpar(RACIONAL *rac);

RACIONAL *adicao(RACIONAL *v1, RACIONAL *v2);
RACIONAL *multiplicacao(RACIONAL *v1, RACIONAL *v2);

void imprimir(RACIONAL *rac);

#endif
