#ifndef FILA_H
#define FILA_H

#include <stdbool.h>

typedef int ITEM; // Pode ser alterado para qualquer tipo ou struct (ex: ITEM*)
typedef struct fila_ FILA;

FILA *fila_cria(void);
void fila_apagar(FILA **fila);
bool fila_entra(FILA *fila, ITEM item);
ITEM fila_sai(FILA *fila);
ITEM fila_frente(FILA *fila);
int fila_tamanho(FILA *fila);
bool fila_vazia(FILA *fila);

#endif