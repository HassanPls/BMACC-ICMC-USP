#include <stdio.h>
#include "lista.h"

int main(void) {
    /* 
    printf("=== TESTE DO TAD LISTA SEQUENCIAL NAO ORDENADA ===\n\n");

    LISTA *l = lista_criar();
    printf("Lista criada. Esta vazia? %s\n", lista_vazia(l) ? "SIM" : "NAO");

    lista_inserir(l, 10);
    lista_inserir(l, 20);
    lista_inserir(l, 30);
    printf("\nApos inserir 10, 20, 30 no final:\n");
    lista_imprimir(l);

    lista_inserir_pos(l, 2, 15);
    printf("\nApos inserir 15 na posicao 2:\n");
    lista_imprimir(l);

    int pos = lista_busca(20, l);
    printf("\nBusca do elemento 20: Posicao relativa %d\n", pos);

    lista_remover_pos(l, 1);
    printf("\nApos remover a posicao 1 (item 10):\n");
    lista_imprimir(l);

    lista_remover(l, 30); 
    printf("\nApos remover o elemento 30 por chave:\n");
    lista_imprimir(l);

    lista_apagar(&l);
    printf("\nLista apagada com sucesso. Ponteiro atual: %s\n", (l == NULL) ? "NULL" : "NAO NULL");
    */

    printf("=== TESTE DO TAD LISTA SEQUENCIAL ORDENADA ===\n\n");

    LISTA *l = lista_criar();
    
    printf("Inserindo elementos: 50, 10, 30, 20, 40...\n");
    lista_inserir(l, 50);
    lista_inserir(l, 10);
    lista_inserir(l, 30);
    lista_inserir(l, 20);
    lista_inserir(l, 40);

    lista_imprimir(l);

    int pos = lista_busca(30, l);
    printf("\nBusca Binaria por 30: Encontrado na posicao %d\n", pos);

    pos = lista_busca(99, l);
    printf("Busca Binaria por 99: %s\n", (pos == ERRO) ? "Nao encontrado" : "Encontrado");

    printf("\nRemovendo o elemento 30...\n");
    lista_remover(l, 30);
    lista_imprimir(l);

    lista_apagar(&l);

    return 0;
}