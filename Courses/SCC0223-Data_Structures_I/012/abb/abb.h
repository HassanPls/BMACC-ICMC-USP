#ifndef ABB_H
#define ABB_H

#include <stdbool.h>

#define TRUE 1
#define FALSE 0
#define ERRO -32000

typedef int ITEM;
typedef struct arv ARV;

ARV *abb_criar(void);
void abb_apagar(ARV **T);
bool abb_vazia(ARV *T);
bool abb_inserir(ARV *T, ITEM item);
ITEM *abb_buscar(ARV *T, int chave);
bool abb_remover(ARV *T, int chave);

#endif