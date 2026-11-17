#include <stdio.h>
#include "pilha.h"

int main(void) {
    int resto, quociente;
    PILHA *p = pilha_criar();

    printf("Entre um numero inteiro positivo: ");
    scanf("%d", &quociente);

    if (quociente == 0) {
        pilha_push(p, 0);
    } else {
        while (quociente != 0) {
            resto = quociente % 2;
            quociente /= 2;
            pilha_push(p, resto);
        }
    }

    printf("A representacao em binario eh: ");
    while (!pilha_vazia(p)) {
        printf("%d", pilha_pop(p));
    }
    printf("\n");

    pilha_apagar(&p);
    return 0;
}