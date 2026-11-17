#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

#define ERRO -1 // Valor sentinela caso ITEM seja int

typedef struct no_ {
    ITEM item;
    struct no_ *proximo;
} NO;

struct fila_ {
    NO *inicio;
    NO *fim;
    int tamanho;
};

FILA *fila_cria(void) {
    FILA *fila = (FILA *) malloc(sizeof(FILA));
    if (fila != NULL) {
        fila->inicio = NULL;
        fila->fim = NULL;
        fila->tamanho = 0;
    }
    return fila;
}

bool fila_vazia(FILA *fila) {
    return (fila == NULL || fila->tamanho == 0);
}

int fila_tamanho(FILA *fila) {
    return (fila != NULL) ? fila->tamanho : -1;
}

bool fila_entra(FILA *fila, ITEM item) {
    if (fila == NULL) return false;

    NO *pnovo = (NO *) malloc(sizeof(NO));
    if (pnovo == NULL) return false;

    pnovo->item = item;
    pnovo->proximo = NULL;

    if (fila_vazia(fila)) {
        fila->inicio = pnovo;
    } else {
        fila->fim->proximo = pnovo;
    }
    
    fila->fim = pnovo;
    fila->tamanho++;
    return true;
}

ITEM fila_sai(FILA *fila) {
    if (fila_vazia(fila)) return ERRO;

    NO *prem = fila->inicio;
    ITEM item = prem->item;

    fila->inicio = prem->proximo;
    if (fila->inicio == NULL) {
        fila->fim = NULL; // A fila ficou vazia
    }

    free(prem);
    fila->tamanho--;
    return item;
}

ITEM fila_frente(FILA *fila) {
    if (fila_vazia(fila)) return ERRO;
    return fila->inicio->item;
}

void fila_apagar(FILA **fila) {
    if (fila != NULL && *fila != NULL) {
        while (!fila_vazia(*fila)) {
            fila_sai(*fila);
        }
        free(*fila);
        *fila = NULL;
    }
}