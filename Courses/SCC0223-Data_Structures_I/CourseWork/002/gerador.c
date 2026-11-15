#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Uso: %s <rajada> <n>\n", argv[0]);
        return 1;
    }

    char* rajada = argv[1];
    int n = atoi(argv[2]);
    int m = 2 * n; // O número de comandos da rajada é 2n

    srand(time(NULL));

    // O primeiro comando é sempre BARALHO n
    printf("BARALHO %d\n", n);

    for (int i = 0; i < m; i++) {
        if (strcmp(rajada, "SOBE") == 0) {
            int x = (rand() % n) + 1;
            printf("SOBE %d\n", x);
        } 
        else if (strcmp(rajada, "CARTA") == 0) {
            int p = (rand() % n) + 1;
            printf("CARTA %d\n", p);
        } 
        else if (strcmp(rajada, "POSICAO") == 0) {
            int x = (rand() % n) + 1;
            printf("POSICAO %d\n", x);
        } 
        else if (strcmp(rajada, "CORTA") == 0) {
            // Sorteia entre CORTA x e VIRA com a mesma probabilidade
            if (rand() % 2 == 0) {
                int x = (rand() % n) + 1;
                printf("CORTA %d\n", x);
            } else {
                printf("VIRA\n");
            }
        } 
        else if (strcmp(rajada, "DESFAZ") == 0) {
            // Alterna entre uma operação modificadora e um DESFAZ
            if (i % 2 == 0) {
                int escolha = rand() % 3;
                if (escolha == 0) {
                    int x = (rand() % n) + 1;
                    printf("CORTA %d\n", x);
                } else if (escolha == 1) {
                    printf("VIRA\n");
                } else {
                    int x = (rand() % n) + 1;
                    printf("SOBE %d\n", x);
                }
            } else {
                printf("DESFAZ\n");
            }
        }
    }

    // Encerra com FIM conforme especificado
    printf("FIM\n");

    return 0;
}