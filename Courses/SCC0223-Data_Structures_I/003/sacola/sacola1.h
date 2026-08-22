#ifndef SACOLA_H
#define SACOLA_H

#define MAX_ELEM 100

typedef int ITEM;

typedef struct sacola SACOLA;

SACOLA *sac_criar_vazia(void);
void sac_limpar(SACOLA *s);
int sac_insere_elem(SACOLA *s, ITEM e);
int sac_conta_elem(SACOLA *s, ITEM e);
void sac_imprimir(SACOLA *s);

#endif