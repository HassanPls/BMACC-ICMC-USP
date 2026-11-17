#include <stdio.h>
#include "fila.h"
#include "deque.h"

int main(void) {
    // Testando Fila
    FILA *f = fila_cria();
    fila_entra(f, 10);
    fila_entra(f, 20);
    fila_entra(f, 30);
    printf("Saiu da fila: %d\n", fila_sai(f)); // 10
    printf("Frente da fila: %d\n", fila_frente(f)); // 20
    fila_apagar(&f);

    // Testando Deque
    DEQUE *d = deque_cria();
    deque_inserir_fim(d, 100);
    deque_inserir_inicio(d, 50);
    deque_inserir_fim(d, 200);
    // Ordem atual: [50, 100, 200]
    printf("Removido do inicio: %d\n", deque_remover_inicio(d)); // 50
    printf("Removido do fim: %d\n", deque_remover_fim(d));       // 200
    deque_apagar(&d);

    return 0;
}