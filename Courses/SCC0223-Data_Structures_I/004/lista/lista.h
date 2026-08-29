#ifndef LISTA_H
#define LISTA_H

#define TAM_MAX 100
#define boolean int
#define FALSE 0
#define TRUE 1
#define ERRO -32000

typedef int ITEM;

typedef struct lista_ LISTA;

LISTA *lista_criar(void);
boolean lista_apagar(LISTA **lista);
int lista_inserir(LISTA *lista, ITEM item);
boolean lista_inserir_pos(LISTA *lista, int pos, ITEM item);
boolean lista_remover(LISTA *lista, ITEM chave);
boolean lista_remover_pos(LISTA *lista, int pos);
int lista_busca(ITEM chave, LISTA *lista);
int lista_tamanho(LISTA *lista);
boolean lista_vazia(LISTA *lista);
boolean lista_cheia(LISTA *lista);
void lista_imprimir(LISTA *lista);

#endif