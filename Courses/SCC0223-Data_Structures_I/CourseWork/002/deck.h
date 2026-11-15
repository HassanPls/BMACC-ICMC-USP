#ifndef DECK_H
#define DECK_H

#define MAX_N 100005

// Definição do Nó da Lista Duplamente Encadeada (com tag struct Node nomeada)
typedef struct Node {
    int label;          // Rótulo da carta (1 a n)
    struct Node* prev;  // Ponteiro para o anterior
    struct Node* next;  // Ponteiro para o próximo
} Node;

// Estrutura principal do Baralho
typedef struct {
    int n;                      // Número atual de cartas
    Node* top;                  // Ponteiro para o nó que está no topo
    int direcao;                // 1 para sentido normal (next), -1 para sentido invertido (prev)
    Node* vetor_cartas[MAX_N];  // Vetor auxiliar de acesso direto por rótulo O(1)
} Deck;

// Funções principais do Baralho
Deck* criar_baralho(int n);
void destruir_baralho(Deck* d);
void cortar(Deck* d, int x);
void sobe(Deck* d, int x);
void vira(Deck* d);
void viratopo(Deck* d, int k);
int carta_na_posicao(Deck* d, int p);
int posicao_da_carta(Deck* d, int x);
void mostra_baralho(Deck* d);

// Tipos de operações que alteram o baralho
typedef enum {
    OP_CORTA,
    OP_SOBE,
    OP_VIRA,
    OP_VIRATOPO
} TipoOp;

// Registro de uma operação no histórico
typedef struct {
    TipoOp tipo;
    int x;              // Parâmetro x (para CORTA/SOBE) ou k (para VIRATOPO)
    Node* prev_node;    // Nó que estava imediatamente antes de 'x' (usado para restaurar SOBE)
    Node* old_top;      // Nó que era o topo antigo (usado para restaurar CORTA)
} Operacao;

// Buffer circular de histórico (máximo 100 elementos)
typedef struct {
    Operacao ops[100];
    int inicio;         // Índice da operação mais antiga
    int qtd;            // Quantidade de operações guardadas (0 a 100)
} Historico;

// Funções de histórico
Historico* criar_historico(void);
void destruir_historico(Historico* h);
void registrar_op(Historico* h, Operacao op);
int desfez_op(Historico* h, Deck* d);
void limpa_historico(Historico* h);

#endif