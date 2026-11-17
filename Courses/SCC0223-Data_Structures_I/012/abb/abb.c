#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

#define FILHO_ESQ 0
#define FILHO_DIR 1

typedef struct no NO;

struct no {
    ITEM item;
    NO *esq;
    NO *dir;
};

struct arv {
    NO *raiz;
};

// --- Funções Auxiliares Internas ---

static void abb_apagar_nos(NO **raiz) {
    if (*raiz != NULL) {
        abb_apagar_nos(&(*raiz)->esq);
        abb_apagar_nos(&(*raiz)->dir);
        free(*raiz);
        *raiz = NULL;
    }
}

static NO *abb_inserir_filho(int filho, NO *no, ITEM item) {
    NO *pnovo = (NO *) malloc(sizeof(NO));
    if (pnovo != NULL) {
        pnovo->dir = NULL;
        pnovo->esq = NULL;
        pnovo->item = item;
        if (filho == FILHO_ESQ)
            no->esq = pnovo;
        else
            no->dir = pnovo;
    }
    return pnovo;
}

static bool abb_inserir_no(NO *raiz, ITEM item) {
    if (item < raiz->item) {
        if (raiz->esq != NULL) {
            return abb_inserir_no(raiz->esq, item);
        } else {
            return (abb_inserir_filho(FILHO_ESQ, raiz, item) != NULL);
        }
    } else if (item > raiz->item) {
        if (raiz->dir != NULL) {
            return abb_inserir_no(raiz->dir, item);
        } else {
            return (abb_inserir_filho(FILHO_DIR, raiz, item) != NULL);
        }
    }
    return false; // Chave duplicada não inserida
}

static NO *abb_buscar_no(NO *raiz, int chave) {
    if (raiz == NULL) return NULL;
    if (chave == raiz->item) return raiz;
    if (chave < raiz->item)
        return abb_buscar_no(raiz->esq, chave);
    else
        return abb_buscar_no(raiz->dir, chave);
}

// Função auxiliar para encontrar o menor elemento da subárvore direita (Caso 3 de remoção)
static NO **encontra_menor(NO **raiz) {
    if ((*raiz)->esq != NULL)
        return encontra_menor(&(*raiz)->esq);
    else {
        NO **aux = raiz;
        return aux;
    }
}

static bool abb_remover_no(NO **raiz, int chave) {
    if (*raiz == NULL) return false;

    if ((*raiz)->item == chave) {
        NO *aux = *raiz;
        // Caso 1 e 2: Nó folha ou possui apenas um filho
        if ((*raiz)->esq == NULL) {
            *raiz = (*raiz)->dir;
            free(aux);
        } else if ((*raiz)->dir == NULL) {
            *raiz = (*raiz)->esq;
            free(aux);
        } else {
            // Caso 3: O nó possui dois filhos
            NO **menor = encontra_menor(&(*raiz)->dir);
            (*raiz)->item = (*menor)->item;
            return abb_remover_no(menor, (*raiz)->item);
        }
        return true;
    } else if (chave < (*raiz)->item) {
        return abb_remover_no(&(*raiz)->esq, chave);
    } else {
        return abb_remover_no(&(*raiz)->dir, chave);
    }
}

// --- Funções Públicas do TAD ---

ARV *abb_criar(void) {
    ARV *r = (ARV *) malloc(sizeof(ARV));
    if (r != NULL) {
        r->raiz = NULL;
    }
    return r;
}

void abb_apagar(ARV **T) {
    if (T != NULL && *T != NULL) {
        abb_apagar_nos(&(*T)->raiz);
        free(*T);
        *T = NULL;
    }
}

bool abb_vazia(ARV *T) {
    return (T == NULL || T->raiz == NULL);
}

bool abb_inserir(ARV *T, ITEM item) {
    if (T == NULL) return false;
    if (abb_vazia(T)) {
        NO *pnovo = (NO *) malloc(sizeof(NO));
        if (pnovo != NULL) {
            pnovo->item = item;
            pnovo->esq = NULL;
            pnovo->dir = NULL;
            T->raiz = pnovo;
            return true;
        }
        return false;
    } else {
        return abb_inserir_no(T->raiz, item);
    }
}

ITEM *abb_buscar(ARV *T, int chave) {
    if (abb_vazia(T)) return NULL;
    NO *no = abb_buscar_no(T->raiz, chave);
    if (no != NULL) return &(no->item);
    return NULL;
}

bool abb_remover(ARV *T, int chave) {
    if (abb_vazia(T)) return false;
    return abb_remover_no(&(T->raiz), chave);
}