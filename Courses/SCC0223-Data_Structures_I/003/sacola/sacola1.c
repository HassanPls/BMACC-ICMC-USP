#include <stdio.h>
#include <stdlib.h>
#include "sacola1.h"

struct sacola {
    ITEM elems[MAX_ELEM];
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

    if (s->used < MAX_ELEM) {
        s->elems[s->used] = e;
        s->used++;
        return 1; 
    } else {
        printf("Erro: A sacola esta cheia!\n");
        return 0; 
    }
}

int sac_conta_elem(SACOLA *s, ITEM e) {
    if (s == NULL) return 0;

    int count = 0;
    for (int i = 0; i < s->used; i++) {
        if (s->elems[i] == e) {
            count++;
        }
    }
    return count;
}

void sac_imprimir(SACOLA *s) {
    if (s == NULL) return;

    printf("Sacola (v1) [%d/%d]: [ ", s->used, MAX_ELEM);
    for (int i = 0; i < s->used; i++) {
        printf("%d ", s->elems[i]);
    }
    printf("]\n");
}