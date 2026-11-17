#ifndef DEQUE_H
#define DEQUE_H

#include <stdbool.h>

typedef int ITEM;
typedef struct deque_ DEQUE;

DEQUE *deque_cria(void);
void deque_apagar(DEQUE **deque);
bool deque_inserir_inicio(DEQUE *deque, ITEM item);
bool deque_inserir_fim(DEQUE *deque, ITEM item);
ITEM deque_remover_inicio(DEQUE *deque);
ITEM deque_remover_fim(DEQUE *deque);
ITEM deque_primeiro(DEQUE *deque);
ITEM deque_ultimo(DEQUE *deque);
int deque_contar(DEQUE *deque);
bool deque_vazia(DEQUE *deque);

#endif