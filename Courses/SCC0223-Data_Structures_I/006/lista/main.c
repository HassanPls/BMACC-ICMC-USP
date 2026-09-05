#include <stdio.h>
#include "lista.h"

int main(void) {
    printf("=== TESTE DA LISTA ENCADEADA DINAMICA ===\n\n");

    LISTA *l = lista_criar();

    printf("Inserindo elementos: 10, 20, 30...\n");
    lista_inserir(l, 10);
    lista_inserir(l, 20);
    lista_inserir(l, 30);
    lista_imprimir(l); 

    printf("\nInserindo 25 na posicao 2...\n");
    lista_inserir_pos(l, 2, 25);
    lista_imprimir(l); 

    int pos = lista_busca(20, l);
    printf("\nBusca do elemento 20: Posicao relativa %d\n", pos);

    printf("\nRemovendo o primeiro nó (posicao 1)...\n");
    lista_remover_pos(l, 1);
    lista_imprimir(l);

    printf("\nRemovendo o elemento 10 por chave...\n");
    lista_remover(l, 10);
    lista_imprimir(l);

    lista_apagar(&l);
    printf("\nLista desalocada com sucesso!\n");

    return 0;
}