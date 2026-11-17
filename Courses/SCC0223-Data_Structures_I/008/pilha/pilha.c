#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef struct no_ {
    ITEM item;
    struct no_ *anterior;
} NO;

struct pilha_ {
    NO *topo;
    int tamanho;
};

PILHA *pilha_criar(void) {
    PILHA *pilha = (PILHA *) malloc(sizeof(PILHA));
    if (pilha != NULL) {
        pilha->topo = NULL;
        pilha->tamanho = 0;
    }
    return pilha;
}

bool pilha_vazia(PILHA *pilha) {
    return (pilha == NULL || pilha->tamanho == 0);
}

int pilha_tamanho(PILHA *pilha) {
    return (pilha != NULL) ? pilha->tamanho : -1;
}

bool pilha_push(PILHA *pilha, ITEM item) {
    if (pilha == NULL) return false;

    NO *pnovo = (NO *) malloc(sizeof(NO));
    if (pnovo == NULL) return false;

    pnovo->item = item;
    pnovo->anterior = pilha->topo;

    pilha->topo = pnovo;
    pilha->tamanho++;
    return true;
}

ITEM pilha_pop(PILHA *pilha) {
    if (pilha_vazia(pilha)) return ERRO;

    NO *paux = pilha->topo;
    ITEM item = paux->item;

    pilha->topo = paux->anterior;
    paux->anterior = NULL;
    free(paux);

    pilha->tamanho--;
    return item;
}

ITEM pilha_topo(PILHA *pilha) {
    if (pilha_vazia(pilha)) return ERRO;
    return pilha->topo->item;
}

void pilha_esvaziar(PILHA *pilha) {
    if (pilha != NULL) {
        while (!pilha_vazia(pilha)) {
            pilha_pop(pilha);
        }
    }
}

void pilha_apagar(PILHA **pilha) {
    if (pilha != NULL && *pilha != NULL) {
        pilha_esvaziar(*pilha);
        free(*pilha);
        *pilha = NULL;
    }
}