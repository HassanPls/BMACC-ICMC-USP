#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct no_ NO;
struct no_ {
    ITEM item;
    NO *proximo;
};

struct lista_ {
    NO *inicio;
};

LISTA *lista_criar(void) {
    LISTA *lista = (LISTA *) malloc(sizeof(LISTA));
    if (lista != NULL) {
        lista->inicio = NULL;
    }
    return lista;
}

boolean lista_apagar(LISTA **lista) {
    if (lista != NULL && *lista != NULL) {
        NO *p = (*lista)->inicio;
        while (p != NULL) {
            NO *aux = p;
            p = p->proximo;
            free(aux);
        }
        free(*lista);
        *lista = NULL;
        return TRUE;
    }
    return FALSE;
}

boolean lista_vazia(LISTA *lista) {
    if (lista != NULL) {
        return (lista->inicio == NULL);
    }
    return TRUE;
}

boolean lista_cheia(LISTA *lista) {
    (void)lista;
    return FALSE;
}

int lista_tamanho(LISTA *lista) {
    if (lista == NULL) return ERRO;

    int tam = 0;
    NO *p = lista->inicio;
    while (p != NULL) {
        tam++;
        p = p->proximo;
    }
    return tam;
}

boolean lista_inserir(LISTA *lista, ITEM item) {
    if (lista == NULL) return FALSE;

    NO *pnovo = (NO *) malloc(sizeof(NO));
    if (pnovo == NULL) return FALSE;

    pnovo->item = item;

    NO *ant = NULL;
    NO *curr = lista->inicio;

    while (curr != NULL && curr->item < item) {
        ant = curr;
        curr = curr->proximo;
    }

    if (ant == NULL) {
        pnovo->proximo = lista->inicio;
        lista->inicio = pnovo;
    } else { 
        pnovo->proximo = curr;
        ant->proximo = pnovo;
    }

    return TRUE;
}

boolean lista_inserir_pos(LISTA *lista, int pos, ITEM item) {
    (void)pos;
    (void)item;
    printf("Aviso: Insercao por posicao arbitraria nao e permitida em listas ordenadas. Use lista_inserir().\n");
    return FALSE;
}

int lista_busca(ITEM chave, LISTA *lista) {
    if (lista == NULL) return ERRO;

    NO *p = lista->inicio;
    int pos = 1;

    while (p != NULL && p->item <= chave) {
        if (p->item == chave) {
            return pos; 
        }
        p = p->proximo;
        pos++;
    }

    return ERRO;
}

boolean lista_remover_pos(LISTA *lista, int pos) {
    if (lista == NULL || lista_vazia(lista) || pos < 1) return FALSE;

    NO *p = lista->inicio;

    if (pos == 1) {
        lista->inicio = p->proximo;
        free(p);
        return TRUE;
    }

    NO *aux = NULL;
    int i = 1;

    while (p != NULL && i < pos) {
        aux = p;
        p = p->proximo;
        i++;
    }

    if (p == NULL) return FALSE;

    aux->proximo = p->proximo;
    free(p);

    return TRUE;
}

boolean lista_remover(LISTA *lista, ITEM chave) {
    if (lista == NULL || lista_vazia(lista)) return FALSE;

    NO *p = lista->inicio;
    NO *aux = NULL;

    while (p != NULL && p->item < chave) {
        aux = p;
        p = p->proximo;
    }

    if (p != NULL && p->item == chave) {
        if (p == lista->inicio) {
            lista->inicio = p->proximo;
        } else {
            aux->proximo = p->proximo;
        }
        free(p);
        return TRUE;
    }

    return FALSE;
}

void lista_imprimir(LISTA *lista) {
    if (lista == NULL) return;

    printf("Lista Encadeada Dinamica Ordenada [%d itens]: [ ", lista_tamanho(lista));
    NO *p = lista->inicio;
    while (p != NULL) {
        printf("%d ", p->item);
        p = p->proximo;
    }
    printf("]\n");
}