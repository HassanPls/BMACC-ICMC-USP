#ifndef PILHA_H
#define PILHA_H

#include <stdbool.h>

#define ERRO -32000

typedef int ITEM;
typedef struct pilha_ PILHA;

PILHA *pilha_criar(void);
void pilha_apagar(PILHA **pilha);
void pilha_esvaziar(PILHA *pilha);
bool pilha_push(PILHA *pilha, ITEM item);
ITEM pilha_pop(PILHA *pilha);
ITEM pilha_topo(PILHA *pilha);
int pilha_tamanho(PILHA *pilha);
bool pilha_vazia(PILHA *pilha);

#endif