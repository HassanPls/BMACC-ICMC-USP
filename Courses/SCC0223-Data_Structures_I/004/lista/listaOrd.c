#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// Definição privada da estrutura
struct lista_ {
    ITEM lista[TAM_MAX];
    int inicio;
    int fim; // Quantidade de elementos armazenados
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

// Inserção Ordenada (Mantém a ordem crescente) - O(n)
int lista_inserir(LISTA *lista, ITEM item) {
    if (lista == NULL || lista_cheia(lista)) {
        return FALSE;
    }

    int i = lista->fim - 1;

    // Desloca elementos maiores que o novo item para a direita
    while (i >= 0 && lista->lista[i] > item) {
        lista->lista[i + 1] = lista->lista[i];
        i--;
    }

    // Insere o elemento na posição correta
    lista->lista[i + 1] = item;
    lista->fim++;

    return TRUE;
}

// Em lista ordenada, inserção por posição arbitrária é desativada/inválida
boolean lista_inserir_pos(LISTA *lista, int pos, ITEM item) {
    (void)pos;
    (void)item;
    printf("Aviso: Insercao por posicao nao permitida em lista ordenada. Use lista_inserir().\n");
    return FALSE;
}

// Busca Binária - O(log n)
int lista_busca(ITEM chave, LISTA *lista) {
    if (lista == NULL || lista_vazia(lista)) {
        return ERRO;
    }

    int low = 0;
    int high = lista->fim - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (lista->lista[mid] == chave) {
            return (mid + 1); // Retorna a posição relativa 1-based
        }
        if (lista->lista[mid] < chave) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ERRO; // Não encontrado
}

boolean lista_remover_pos(LISTA *lista, int pos) {
    if (lista != NULL && !lista_vazia(lista) && pos >= 1 && pos <= lista->fim) {
        // Desloca elementos para a esquerda
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
        printf("Lista Ordenada [%d/%d]: [ ", lista->fim, TAM_MAX);
        for (int i = 0; i < lista->fim; i++) {
            printf("%d ", lista->lista[i]);
        }
        printf("]\n");
    }
}