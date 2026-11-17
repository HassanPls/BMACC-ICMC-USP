#include <stdio.h>
#include "abb.h"

int main(void) {
    ARV *arvore = abb_criar();

    // Inserindo chaves na ABB
    abb_inserir(arvore, 27);
    abb_inserir(arvore, 20);
    abb_inserir(arvore, 90);
    abb_inserir(arvore, 10);
    abb_inserir(arvore, 25);
    abb_inserir(arvore, 100);

    // Testando a busca
    int chave_busca = 25;
    ITEM *resultado = abb_buscar(arvore, chave_busca);
    if (resultado != NULL) {
        printf("Chave %d encontrada com sucesso!\n", *resultado);
    } else {
        printf("Chave %d nao encontrada.\n", chave_busca);
    }

    // Testando a remoção
    printf("Removendo o no 20 (caso de subarvores)...\n");
    if (abb_remover(arvore, 20)) {
        printf("Elemento 20 removido.\n");
    }

    // Buscando o elemento removido
    if (abb_buscar(arvore, 20) == NULL) {
        printf("Confirmado: chave 20 nao esta mais na arvore.\n");
    }

    // Apagando a árvore da memória
    abb_apagar(&arvore);
    printf("Arvore apagada e memoria liberada com sucesso.\n");

    return 0;
}