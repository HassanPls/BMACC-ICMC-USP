#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "deck.h"

int main(void) {
    char comando[20];
    Deck* deck = NULL;
    Historico* hist = criar_historico();

    while (scanf("%s", comando) != EOF) {
        if (strcmp(comando, "BARALHO") == 0) {
            int n;
            if (scanf("%d", &n) != 1) {}

            // Se já existia um baralho ou histórico anterior, limpa-os
            if (deck) {
                destruir_baralho(deck);
            }
            limpa_historico(hist);

            deck = criar_baralho(n);
        } 
        else if (strcmp(comando, "CORTA") == 0) {
            int x;
            if (scanf("%d", &x) != 1) {}

            if (deck) {
                // Regista a operação no histórico antes de a executar
                Operacao op;
                op.tipo = OP_CORTA;
                op.x = x;
                op.prev_node = NULL;
                op.old_top = deck->top; // Guarda o topo antigo para reverter o corte
                registrar_op(hist, op);

                cortar(deck, x);
            }
        } 
        else if (strcmp(comando, "SOBE") == 0) {
            int x;
            if (scanf("%d", &x) != 1) {}

            if (deck) {
                Node* alvo = deck->vetor_cartas[x];
                Operacao op;
                op.tipo = OP_SOBE;
                op.x = x;
                op.prev_node = alvo ? alvo->prev : NULL; // Guarda o nó anterior para restaurar a posição original
                op.old_top = deck->top;
                registrar_op(hist, op);

                sobe(deck, x);
            }
        } 
        else if (strcmp(comando, "VIRA") == 0) {
            if (deck) {
                Operacao op;
                op.tipo = OP_VIRA;
                op.x = 0;
                op.prev_node = NULL;
                op.old_top = deck->top;
                registrar_op(hist, op);

                vira(deck);
            }
        } 
        else if (strcmp(comando, "VIRATOPO") == 0) {
            int k;
            if (scanf("%d", &k) != 1) {}

            if (deck) {
                Operacao op;
                op.tipo = OP_VIRATOPO;
                op.x = k;
                op.prev_node = NULL;
                op.old_top = deck->top;
                registrar_op(hist, op);

                viratopo(deck, k);
            }
        } 
        else if (strcmp(comando, "DESFAZ") == 0) {
            if (deck && hist) {
                desfez_op(hist, deck);
            }
        } 
        else if (strcmp(comando, "CARTA") == 0) {
            int p;
            if (scanf("%d", &p) != 1) {}

            if (deck) {
                int rotulo = carta_na_posicao(deck, p);
                printf("%d\n", rotulo);
            }
        } 
        else if (strcmp(comando, "POSICAO") == 0) {
            int x;
            if (scanf("%d", &x) != 1) {}

            if (deck) {
                int pos = posicao_da_carta(deck, x);
                printf("%d\n", pos);
            }
        } 
        else if (strcmp(comando, "MOSTRA") == 0) {
            if (deck) {
                mostra_baralho(deck);
            }
        } 
        else if (strcmp(comando, "FIM") == 0) {
            break;
        }
    }

    // Libertação final de memória para evitar fugas detectadas pelo Valgrind
    if (deck) {
        destruir_baralho(deck);
    }
    destruir_historico(hist);

    return 0;
}