#include <stdio.h>
#include "sacola2.h"

int main() {
    /* SACOLA *s = sac_criar_vazia();

    sac_insere_elem(s, 10);
    sac_insere_elem(s, 20);
    sac_insere_elem(s, 10);
    sac_insere_elem(s, 30);
    sac_insere_elem(s, 10);

    sac_imprimir(s);

    printf("Quantidade do elemento 10: %d\n", sac_conta_elem(s, 10)); 
    printf("Quantidade do elemento 20: %d\n", sac_conta_elem(s, 20)); 
    printf("Quantidade do elemento 99: %d\n", sac_conta_elem(s, 99)); 

    sac_limpar(s); */

    //===========================================

    SACOLA *s = sac_criar_vazia();
    if (s == NULL) {
        printf("Erro ao alocar a sacola!\n");
        return 1;
    }

    sac_insere_elem(s, 10);
    sac_insere_elem(s, 20);
    sac_insere_elem(s, 10);
    sac_insere_elem(s, 30);
    sac_insere_elem(s, 10);
    sac_insere_elem(s, 20);

    sac_imprimir(s);

    printf("Frequencia do elemento 10: %d (Esperado: 3)\n", sac_conta_elem(s, 10));
    printf("Frequencia do elemento 20: %d (Esperado: 2)\n", sac_conta_elem(s, 20));
    printf("Frequencia do elemento 30: %d (Esperado: 1)\n", sac_conta_elem(s, 30));
    printf("Frequencia do elemento 99: %d (Esperado: 0)\n", sac_conta_elem(s, 99));

    sac_limpar(s);

    return 0;
}