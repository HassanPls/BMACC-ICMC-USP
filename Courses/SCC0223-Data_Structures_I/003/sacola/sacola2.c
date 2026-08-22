#include <stdio.h>
#include <stdlib.h>
#include "sacola2.h"

typedef struct {
    ITEM valor;
    int num;
} ELEMENTO;

struct sacola {
    ELEMENTO elems[MAX_ELEM];
    int used;                
};

SACOLA *sac_criar_vazia(void) {
    SACOLA *s = (SACOLA *) malloc(sizeof(SACOLA));
    if (s != NULL) {
        s->used = 0;
    }
    return s;
}

void sac_limpar(SACOLA *s) {
    if (s != NULL) {
        free(s);
    }
}

int sac_insere_elem(SACOLA *s, ITEM e) {
    if (s == NULL) return 0;

    int index = 0;
    while (index < s->used && s->elems[index].valor != e) {
        index++;
    }

    if (index < s->used) {
        s->elems[index].num++;
        return 1;
    }

    if (s->used < MAX_ELEM) {
        s->elems[s->used].valor = e;
        s->elems[s->used].num = 1;
        s->used++;
        return 1;
    } else {
        printf("Erro: A sacola esta cheia de elementos distintos!\n");
        return 0;
    }
}

int sac_conta_elem(SACOLA *s, ITEM e) {
    if (s == NULL) return 0;

    for (int i = 0; i < s->used; i++) {
        if (s->elems[i].valor == e) {
            return s->elems[i].num; 
        }
    }
    return 0; 
}

void sac_imprimir(SACOLA *s) {
    if (s == NULL) return;

    printf("Sacola (v2) [%d posicoes usadas]: [ ", s->used);
    for (int i = 0; i < s->used; i++) {
        printf("(val: %d, qtd: %d) ", s->elems[i].valor, s->elems[i].num);
    }
    printf("]\n");
}