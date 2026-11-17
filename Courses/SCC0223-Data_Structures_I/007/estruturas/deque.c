#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

#define ERRO -1

typedef struct no_ {
    ITEM item;
    struct no_ *anterior;
    struct no_ *proximo;
} NO;

struct deque_ {
    NO *inicio;
    NO *fim;
    int tamanho;
};

DEQUE *deque_cria(void) {
    DEQUE *deque = (DEQUE *) malloc(sizeof(DEQUE));
    if (deque != NULL) {
        deque->inicio = NULL;
        deque->fim = NULL;
        deque->tamanho = 0;
    }
    return deque;
}

bool deque_vazia(DEQUE *deque) {
    return (deque == NULL || deque->tamanho == 0);
}

int deque_contar(DEQUE *deque) {
    return (deque != NULL) ? deque->tamanho : -1;
}

bool deque_inserir_inicio(DEQUE *deque, ITEM item) {
    if (deque == NULL) return false;

    NO *pnovo = (NO *) malloc(sizeof(NO));
    if (pnovo == NULL) return false;

    pnovo->item = item;
    pnovo->anterior = NULL;
    pnovo->proximo = deque->inicio;

    if (deque_vazia(deque)) {
        deque->fim = pnovo;
    } else {
        deque->inicio->anterior = pnovo;
    }

    deque->inicio = pnovo;
    deque->tamanho++;
    return true;
}

bool deque_inserir_fim(DEQUE *deque, ITEM item) {
    if (deque == NULL) return false;

    NO *pnovo = (NO *) malloc(sizeof(NO));
    if (pnovo == NULL) return false;

    pnovo->item = item;
    pnovo->proximo = NULL;
    pnovo->anterior = deque->fim;

    if (deque_vazia(deque)) {
        deque->inicio = pnovo;
    } else {
        deque->fim->proximo = pnovo;
    }

    deque->fim = pnovo;
    deque->tamanho++;
    return true;
}

ITEM deque_remover_inicio(DEQUE *deque) {
    if (deque_vazia(deque)) return ERRO;

    NO *prem = deque->inicio;
    ITEM item = prem->item;

    deque->inicio = prem->proximo;
    if (deque->inicio == NULL) {
        deque->fim = NULL;
    } else {
        deque->inicio->anterior = NULL;
    }

    free(prem);
    deque->tamanho--;
    return item;
}

ITEM deque_remover_fim(DEQUE *deque) {
    if (deque_vazia(deque)) return ERRO;

    NO *prem = deque->fim;
    ITEM item = prem->item;

    deque->fim = prem->anterior;
    if (deque->fim == NULL) {
        deque->inicio = NULL;
    } else {
        deque->fim->proximo = NULL;
    }

    free(prem);
    deque->tamanho--;
    return item;
}

ITEM deque_primeiro(DEQUE *deque) {
    if (deque_vazia(deque)) return ERRO;
    return deque->inicio->item;
}

ITEM deque_ultimo(DEQUE *deque) {
    if (deque_vazia(deque)) return ERRO;
    return deque->fim->item;
}

void deque_apagar(DEQUE **deque) {
    if (deque != NULL && *deque != NULL) {
        while (!deque_vazia(*deque)) {
            deque_remover_inicio(*deque);
        }
        free(*deque);
        *deque = NULL;
    }
}