#include <stdio.h>
#include <stdlib.h>
#include "polinomio.h"

typedef struct no_ {
    long long coef;
    long long grau;
    struct no_ *proximo;
} NO;

struct polinomio_ {
    NO *cabeca;
    NO *fim;
};

static NO *criar_no(long long coef, long long grau)
{
    NO *novo = malloc(sizeof(NO));

    if (novo == NULL)
        return NULL;

    novo->coef = coef;
    novo->grau = grau;
    novo->proximo = NULL;

    return novo;
}

POLINOMIO *criar(void)
{
    POLINOMIO *p = malloc(sizeof(POLINOMIO));

    if (p == NULL)
        return NULL;

    p->cabeca = criar_no(0, -1);

    if (p->cabeca == NULL) {
        free(p);
        return NULL;
    }

    p->cabeca->proximo = p->cabeca;
    p->fim = p->cabeca;

    return p;
}

void destruir(POLINOMIO **p)
{
    if (p == NULL || *p == NULL)
        return;

    NO *atual = (*p)->cabeca->proximo;

    while (atual != (*p)->cabeca) {
        NO *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    free((*p)->cabeca);
    free(*p);
    *p = NULL;
}

void inserir_ou_somar_termo(
    POLINOMIO *p,
    long long coef,
    long long grau)
{
    if (p == NULL || coef == 0)
        return;

    NO *anterior = p->cabeca;
    NO *atual = p->cabeca->proximo;

    while (atual != p->cabeca && atual->grau < grau) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual != p->cabeca && atual->grau == grau) {

        atual->coef += coef;

        if (atual->coef == 0) {

            anterior->proximo = atual->proximo;

            if (atual == p->fim)
                p->fim = anterior;

            free(atual);
        }

        return;
    }

    NO *novo = criar_no(coef, grau);

    if (novo == NULL)
        return;

    novo->proximo = atual;
    anterior->proximo = novo;

    if (anterior == p->fim)
        p->fim = novo;
}

void remover_termo(POLINOMIO *p, long long grau)
{
    if (p == NULL)
        return;

    NO *anterior = p->cabeca;
    NO *atual = p->cabeca->proximo;

    while (atual != p->cabeca && atual->grau < grau) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == p->cabeca || atual->grau != grau)
        return;

    anterior->proximo = atual->proximo;

    if (atual == p->fim)
        p->fim = anterior;

    free(atual);
}

void remover_menor_grau(POLINOMIO *p)
{
    if (p == NULL || eh_nulo(p))
        return;

    NO *menor = p->cabeca->proximo;

    p->cabeca->proximo = menor->proximo;

    if (menor == p->fim)
        p->fim = p->cabeca;

    free(menor);
}

void escala(POLINOMIO *p, long long c)
{
    if (p == NULL)
        return;

    if (c == 0) {

        NO *atual = p->cabeca->proximo;

        while (atual != p->cabeca) {
            NO *proximo = atual->proximo;
            free(atual);
            atual = proximo;
        }

        p->cabeca->proximo = p->cabeca;
        p->fim = p->cabeca;

        return;
    }

    NO *atual = p->cabeca->proximo;

    while (atual != p->cabeca) {
        atual->coef *= c;
        atual = atual->proximo;
    }
}

long long obter_coef(const POLINOMIO *p, long long grau)
{
    if (p == NULL || eh_nulo(p))
        return 0;

    NO *atual = p->cabeca->proximo;

    while (atual != p->cabeca && atual->grau < grau)
        atual = atual->proximo;

    if (atual != p->cabeca && atual->grau == grau)
        return atual->coef;

    return 0;
}

long long obter_grau(const POLINOMIO *p)
{
    if (p == NULL || eh_nulo(p))
        return -1;

    return p->fim->grau;
}

bool eh_nulo(const POLINOMIO *p)
{
    if (p == NULL)
        return true;

    return p->cabeca->proximo == p->cabeca;
}

POLINOMIO *somar(const POLINOMIO *a, const POLINOMIO *b)
{
    POLINOMIO *resultado = criar();

    if (resultado == NULL)
        return NULL;

    if (a == NULL && b == NULL)
        return resultado;

    if (a == NULL) {
        const NO *atual = b->cabeca->proximo;

        while (atual != b->cabeca) {
            inserir_ou_somar_termo(
                resultado,
                atual->coef,
                atual->grau
            );

            atual = atual->proximo;
        }

        return resultado;
    }

    if (b == NULL) {
        const NO *atual = a->cabeca->proximo;

        while (atual != a->cabeca) {
            inserir_ou_somar_termo(
                resultado,
                atual->coef,
                atual->grau
            );

            atual = atual->proximo;
        }

        return resultado;
    }

    const NO *p1 = a->cabeca->proximo;
    const NO *p2 = b->cabeca->proximo;

    while (p1 != a->cabeca && p2 != b->cabeca) {

        if (p1->grau < p2->grau) {

            inserir_ou_somar_termo(
                resultado,
                p1->coef,
                p1->grau
            );

            p1 = p1->proximo;

        } else if (p2->grau < p1->grau) {

            inserir_ou_somar_termo(
                resultado,
                p2->coef,
                p2->grau
            );

            p2 = p2->proximo;

        } else {

            inserir_ou_somar_termo(
                resultado,
                p1->coef + p2->coef,
                p1->grau
            );

            p1 = p1->proximo;
            p2 = p2->proximo;
        }
    }

    while (p1 != a->cabeca) {

        inserir_ou_somar_termo(
            resultado,
            p1->coef,
            p1->grau
        );

        p1 = p1->proximo;
    }

    while (p2 != b->cabeca) {

        inserir_ou_somar_termo(
            resultado,
            p2->coef,
            p2->grau
        );

        p2 = p2->proximo;
    }

    return resultado;
}

POLINOMIO *multiplicar(const POLINOMIO *a, const POLINOMIO *b)
{
    POLINOMIO *resultado = criar();

    if (resultado == NULL)
        return NULL;

    if (a == NULL || b == NULL ||
        eh_nulo(a) || eh_nulo(b)) {
        return resultado;
    }

    const NO *p1 = a->cabeca->proximo;

    while (p1 != a->cabeca) {

        const NO *p2 = b->cabeca->proximo;

        while (p2 != b->cabeca) {

            long long coef = p1->coef * p2->coef;
            long long grau = p1->grau + p2->grau;

            inserir_ou_somar_termo(
                resultado,
                coef,
                grau
            );

            p2 = p2->proximo;
        }

        p1 = p1->proximo;
    }

    return resultado;
}

static void imprimir_termo(
    long long coef,
    long long grau,
    bool primeiro)
{
    if (!primeiro)
        printf(" ");

    printf("%lld*x^%lld", coef, grau);
}

static void imprimir_canonica_rec(
    const NO *atual,
    const NO *cabeca,
    bool *primeiro)
{
    if (atual == cabeca)
        return;

    imprimir_canonica_rec(
        atual->proximo,
        cabeca,
        primeiro
    );

    imprimir_termo(
        atual->coef,
        atual->grau,
        *primeiro
    );

    *primeiro = false;
}

void imprimir_canonica(const POLINOMIO *p)
{
    if (p == NULL || eh_nulo(p)) {
        printf("0\n");
        return;
    }

    bool primeiro = true;

    imprimir_canonica_rec(
        p->cabeca->proximo,
        p->cabeca,
        &primeiro
    );

    printf("\n");
}

void imprimir_crescente(const POLINOMIO *p)
{
    if (p == NULL || eh_nulo(p)) {
        printf("0\n");
        return;
    }

    const NO *atual = p->cabeca->proximo;
    bool primeiro = true;

    while (atual != p->cabeca) {

        imprimir_termo(
            atual->coef,
            atual->grau,
            primeiro
        );

        primeiro = false;
        atual = atual->proximo;
    }

    printf("\n");
}