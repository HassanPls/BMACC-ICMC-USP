#include <stdio.h>
#include <stdlib.h>
#include "listaNoOrd.h"

struct lista_ {
    ITEM lista[TAM_MAX];
    int inicio;
    int fim; 
};

LISTA *lista_criar(void) {
    LISTA *lista = (LISTA *) malloc(sizeof(LISTA));
    if (lista != NULL) {
        lista->inicio = 0;
        lista->fim = 0; 
    }
    return lista;
}

boolean lista_apagar(LISTA **lista) {
    if (lista != NULL && *lista != NULL) {
        free(*lista);
        *lista = NULL;
        return TRUE;
    }
    return FALSE;
}

boolean lista_vazia(LISTA *lista) {
    if (lista != NULL) {
        return (lista->fim == lista->inicio);
    }
    return TRUE;
}

boolean lista_cheia(LISTA *lista) {
    if (lista != NULL) {
        return (lista->fim == TAM_MAX);
    }
    return FALSE;
}

int lista_tamanho(LISTA *lista) {
    if (lista != NULL) {
        return lista->fim;
    }
    return ERRO;
}

int lista_inserir(LISTA *lista, ITEM item) {
    if (lista != NULL && !lista_cheia(lista)) {
        lista->lista[lista->fim] = item;
        lista->fim++;
        return TRUE;
    }
    return FALSE;
}

boolean lista_inserir_pos(LISTA *lista, int pos, ITEM item) {
    if (lista != NULL && !lista_cheia(lista) && pos >= 1 && pos <= lista->fim + 1) {
        for (int i = lista->fim - 1; i >= pos - 1; i--) {
            lista->lista[i + 1] = lista->lista[i];
        }
        lista->lista[pos - 1] = item;
        lista->fim++;
        return TRUE;
    }
    return FALSE;
}

int lista_busca(ITEM chave, LISTA *lista) {
    if (lista != NULL) {
        for (int i = 0; i < lista->fim; i++) {
            if (lista->lista[i] == chave) {
                return (i + 1); 
            }
        }
    }
    return ERRO;
}

boolean lista_remover_pos(LISTA *lista, int pos) {
    if (lista != NULL && !lista_vazia(lista) && pos >= 1 && pos <= lista->fim) {
        for (int i = pos - 1; i < lista->fim - 1; i++) {
            lista->lista[i] = lista->lista[i + 1];
        }
        lista->fim--;
        return TRUE;
    }
    return FALSE;
}

boolean lista_remover(LISTA *lista, ITEM chave) {
    int pos = lista_busca(chave, lista);
    if (pos != ERRO) {
        return lista_remover_pos(lista, pos);
    }
    return FALSE;
}

void lista_imprimir(LISTA *lista) {
    if (lista != NULL) {
        printf("Lista [%d/%d]: [ ", lista->fim, TAM_MAX);
        for (int i = 0; i < lista->fim; i++) {
            printf("%d ", lista->lista[i]);
        }
        printf("]\n");
    }
}