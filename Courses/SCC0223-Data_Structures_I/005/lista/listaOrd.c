#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct {
    ITEM item;
    int proximo;
} NO;

struct lista_ {
    NO lista[TAM_MAX];
    int inicio;
    int disponivel;
};

LISTA *lista_criar(void) {
    LISTA *lista = (LISTA *) malloc(sizeof(LISTA));
    if (lista != NULL) {
        lista->inicio = NULO;
        lista->disponivel = 0;

        for (int i = 0; i < TAM_MAX - 1; i++) {
            lista->lista[i].proximo = i + 1;
        }
        lista->lista[TAM_MAX - 1].proximo = NULO;
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
        return (lista->inicio == NULO);
    }
    return TRUE;
}

boolean lista_cheia(LISTA *lista) {
    if (lista != NULL) {
        return (lista->disponivel == NULO);
    }
    return TRUE;
}

int lista_tamanho(LISTA *lista) {
    if (lista == NULL) return ERRO;

    int tam = 0;
    int curr = lista->inicio;
    while (curr != NULO) {
        tam++;
        curr = lista->lista[curr].proximo;
    }
    return tam;
}

int lista_inserir(LISTA *lista, ITEM item) {
    if (lista == NULL || lista_cheia(lista)) {
        return FALSE;
    }

    int ant = NULO;
    int curr = lista->inicio;

    while (curr != NULO && lista->lista[curr].item < item) {
        ant = curr;
        curr = lista->lista[curr].proximo;
    }

    int dispo = lista->disponivel;
    lista->disponivel = lista->lista[dispo].proximo;

    lista->lista[dispo].item = item;

    if (ant == NULO) {
        lista->lista[dispo].proximo = lista->inicio;
        lista->inicio = dispo;
    } else { 
        lista->lista[dispo].proximo = curr;
        lista->lista[ant].proximo = dispo;
    }

    return TRUE;
}

boolean lista_inserir_pos(LISTA *lista, int pos, ITEM item) {
    (void)pos;
    (void)item;
    printf("Aviso: Insercao por posicao nao e permitida em listas ordenadas. Use lista_inserir().\n");
    return FALSE;
}

int lista_busca(ITEM chave, LISTA *lista) {
    if (lista == NULL) return ERRO;

    int curr = lista->inicio;
    int pos = 1;

    while (curr != NULO && lista->lista[curr].item <= chave) {
        if (lista->lista[curr].item == chave) {
            return pos;
        }
        curr = lista->lista[curr].proximo;
        pos++;
    }

    return ERRO;
}

boolean lista_remover_pos(LISTA *lista, int pos) {
    if (lista == NULL || lista_vazia(lista) || pos < 1) {
        return FALSE;
    }

    int removido = NULO;

    if (pos == 1) {
        removido = lista->inicio;
        lista->inicio = lista->lista[removido].proximo;
    } else {
        int curr = lista->inicio;
        int i = 1;

        while (curr != NULO && i < pos - 1) {
            curr = lista->lista[curr].proximo;
            i++;
        }

        if (curr == NULO || lista->lista[curr].proximo == NULO) {
            return FALSE;
        }

        removido = lista->lista[curr].proximo;
        lista->lista[curr].proximo = lista->lista[removido].proximo;
    }

    lista->lista[removido].proximo = lista->disponivel;
    lista->disponivel = removido;

    return TRUE;
}

boolean lista_remover(LISTA *lista, ITEM chave) {
    int pos = lista_busca(chave, lista);
    if (pos != ERRO) {
        return lista_remover_pos(lista, pos);
    }
    return FALSE;
}

void lista_imprimir(LISTA *lista) {
    if (lista == NULL) return;

    printf("Lista Encadeada Estatica Ordenada [%d itens]: [ ", lista_tamanho(lista));
    int curr = lista->inicio;
    while (curr != NULO) {
        printf("%d ", lista->lista[curr].item);
        curr = lista->lista[curr].proximo;
    }
    printf("]\n");
}