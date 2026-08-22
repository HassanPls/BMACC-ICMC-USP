#include "stdio.h"
#include "stdlib.h"
#include "racional.h"

struct racional
{
    int num;
    int den;
};

RACIONAL* criar(int num, int den) {
    if (den == 0) {
        return NULL;
    }

    RACIONAL *rac = (RACIONAL*) malloc(sizeof(RACIONAL)); 
    rac -> num = num;
    rac -> den = den;

    return rac;
}

void limpar(RACIONAL *rac) {
    if (rac != NULL) {
        free(rac);
    }
}

void imprimir(RACIONAL *rac) {
    if (rac != NULL) {
        printf("%d/%d\n", rac->num, rac->den);
    } else {
        printf("Racional invalido (NULL)\n");
    }
}

RACIONAL *adicao(RACIONAL *v1, RACIONAL *v2) {
    if (v1 == NULL || v2 == NULL) return NULL;

    int num_resultado = (v1->num * v2->den) + (v2->num * v1->den);
    int den_resultado = v1->den * v2->den;

    return criar(num_resultado, den_resultado);
}

RACIONAL *multiplicacao(RACIONAL *v1, RACIONAL *v2) {
    if (v1 == NULL || v2 == NULL) return NULL;

    int num_resultado = v1->num * v2->num;
    int den_resultado = v1->den * v2->den;

    return criar(num_resultado, den_resultado);
}
