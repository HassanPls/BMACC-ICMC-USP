#include <stdio.h>
#include "lista.h"

int main(void) {
    printf("=== TESTE DA LISTA ENCADEADA ESTATICA (NAO ORDENADA) ===\n\n");

    LISTA *l = lista_criar();

    // 1. Inserção no início O(1)
    printf("Inserindo elementos: 10, 20, 30...\n");
    lista_inserir(l, 10);
    lista_inserir(l, 20);
    lista_inserir(l, 30);
    lista_imprimir(l); // Ordem esperada: 30 20 10

    // 2. Inserção na 2ª posição
    printf("\nInserindo 25 na posicao 2...\n");
    lista_inserir_pos(l, 2, 25);
    lista_imprimir(l); // Ordem esperada: 30 25 20 10

    // 3. Busca
    int pos = lista_busca(20, l);
    printf("\nBusca pelo elemento 20: Posicao %d\n", pos);

    // 4. Remoção da 1ª posição e por chave
    printf("\nRemovendo elemento da posicao 1 (item 30)...\n");
    lista_remover_pos(l, 1);
    lista_imprimir(l);

    printf("\nRemovendo o elemento 10 por chave...\n");
    lista_remover(l, 10);
    lista_imprimir(l);

    // 5. Destruição
    lista_apagar(&l);
    printf("\nLista apagada com sucesso!\n");

    return 0;
}