#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include "polinomio.h"

#define MAX_POLIS 512
#define MAX_NOME 33

typedef struct {
    char nome[MAX_NOME];
    POLINOMIO *p;
    bool ativo;
} TabelaItem;

static TabelaItem tabela[MAX_POLIS];

static int buscar_polinomio(const char *nome) {
    for (int i = 0; i < MAX_POLIS; i++) {
        if (tabela[i].ativo && strcmp(tabela[i].nome, nome) == 0) {
            return i;
        }
    }
    return -1;
}

static int obter_ou_criar_slot(const char *nome) {
    int idx = buscar_polinomio(nome);
    if (idx != -1) {
        return idx;
    }
    for (int i = 0; i < MAX_POLIS; i++) {
        if (!tabela[i].ativo) {
            strncpy(tabela[i].nome, nome, MAX_NOME - 1);
            tabela[i].nome[MAX_NOME - 1] = '\0';
            tabela[i].p = NULL;
            tabela[i].ativo = true;
            return i;
        }
    }
    return -1;
}

static void liberar_slot(int idx) {
    if (idx >= 0 && idx < MAX_POLIS && tabela[idx].ativo) {
        if (tabela[idx].p != NULL) {
            destruir(&tabela[idx].p);
        }
        tabela[idx].ativo = false;
        tabela[idx].nome[0] = '\0';
    }
}

static void limpar_tabela(void) {
    for (int i = 0; i < MAX_POLIS; i++) {
        if (tabela[i].ativo) {
            liberar_slot(i);
        }
    }
}

int main(void) {
    char comando[32];

    while (scanf("%31s", comando) == 1) {
        if (strcmp(comando, "FIM") == 0) {
            break;
        }

        if (strcmp(comando, "DEF") == 0) {
            char nome[MAX_NOME];
            long long k;
            if (scanf("%32s %lld", nome, &k) != 2) continue;

            int idx = obter_ou_criar_slot(nome);
            if (tabela[idx].p != NULL) {
                destruir(&tabela[idx].p);
            }
            tabela[idx].p = criar();

            for (long long i = 0; i < k; i++) {
                long long coef, grau;
                if (scanf("%lld %lld", &coef, &grau) == 2) {
                    inserir_ou_somar_termo(tabela[idx].p, coef, grau);
                }
            }
        } 
        else if (strcmp(comando, "SOMA") == 0) {
            char nomeA[MAX_NOME], nomeB[MAX_NOME], nomeR[MAX_NOME];
            if (scanf("%32s %32s %32s", nomeA, nomeB, nomeR) != 3) continue;

            int idxA = buscar_polinomio(nomeA);
            int idxB = buscar_polinomio(nomeB);

            if (idxA != -1 && idxB != -1) {
                POLINOMIO *resultado = somar(tabela[idxA].p, tabela[idxB].p);
                int idxR = obter_ou_criar_slot(nomeR);
                if (tabela[idxR].p != NULL) {
                    destruir(&tabela[idxR].p);
                }
                tabela[idxR].p = resultado;
            }
        } 
        else if (strcmp(comando, "PROD") == 0) {
            char nomeA[MAX_NOME], nomeB[MAX_NOME], nomeR[MAX_NOME];
            if (scanf("%32s %32s %32s", nomeA, nomeB, nomeR) != 3) continue;

            int idxA = buscar_polinomio(nomeA);
            int idxB = buscar_polinomio(nomeB);

            if (idxA != -1 && idxB != -1) {
                POLINOMIO *resultado = multiplicar(tabela[idxA].p, tabela[idxB].p);
                int idxR = obter_ou_criar_slot(nomeR);
                if (tabela[idxR].p != NULL) {
                    destruir(&tabela[idxR].p);
                }
                tabela[idxR].p = resultado;
            }
        } 
        else if (strcmp(comando, "ADD") == 0) {
            char nome[MAX_NOME];
            long long c, g;
            if (scanf("%32s %lld %lld", nome, &c, &g) != 3) continue;

            int idx = buscar_polinomio(nome);
            if (idx != -1) {
                inserir_ou_somar_termo(tabela[idx].p, c, g);
            }
        } 
        else if (strcmp(comando, "ESCALA") == 0) {
            char nome[MAX_NOME];
            long long c;
            if (scanf("%32s %lld", nome, &c) != 2) continue;

            int idx = buscar_polinomio(nome);
            if (idx != -1) {
                escala(tabela[idx].p, c);
            }
        } 
        else if (strcmp(comando, "COEF") == 0) {
            char nome[MAX_NOME];
            long long g;
            if (scanf("%32s %lld", nome, &g) != 2) continue;

            int idx = buscar_polinomio(nome);
            if (idx != -1) {
                printf("%lld\n", obter_coef(tabela[idx].p, g));
            } else {
                printf("0\n");
            }
        } 
        else if (strcmp(comando, "REMOVE") == 0) {
            char nome[MAX_NOME];
            long long g;
            if (scanf("%32s %lld", nome, &g) != 2) continue;

            int idx = buscar_polinomio(nome);
            if (idx != -1) {
                remover_termo(tabela[idx].p, g);
            }
        } 
        else if (strcmp(comando, "REMOVEMENOR") == 0) {
            char nome[MAX_NOME];
            if (scanf("%32s", nome) != 1) continue;

            int idx = buscar_polinomio(nome);
            if (idx != -1) {
                remover_menor_grau(tabela[idx].p);
            }
        } 
        else if (strcmp(comando, "GRAU") == 0) {
            char nome[MAX_NOME];
            if (scanf("%32s", nome) != 1) continue;

            int idx = buscar_polinomio(nome);
            if (idx != -1) {
                printf("%lld\n", obter_grau(tabela[idx].p));
            } else {
                printf("-1\n");
            }
        } 
        else if (strcmp(comando, "IMPRIME") == 0) {
            char nome[MAX_NOME];
            if (scanf("%32s", nome) != 1) continue;

            int idx = buscar_polinomio(nome);
            if (idx != -1) {
                imprimir_canonica(tabela[idx].p);
            } else {
                printf("0\n");
            }
        } 
        else if (strcmp(comando, "IMPRIMEINV") == 0) {
            char nome[MAX_NOME];
            if (scanf("%32s", nome) != 1) continue;

            int idx = buscar_polinomio(nome);
            if (idx != -1) {
                imprimir_crescente(tabela[idx].p);
            } else {
                printf("0\n");
            }
        } 
        else if (strcmp(comando, "LIBERA") == 0) {
            char nome[MAX_NOME];
            if (scanf("%32s", nome) != 1) continue;

            int idx = buscar_polinomio(nome);
            if (idx != -1) {
                liberar_slot(idx);
            }
        }
    }

    limpar_tabela();
    return 0;
}