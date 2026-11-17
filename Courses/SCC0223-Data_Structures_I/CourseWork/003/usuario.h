#ifndef USUARIO_H
#define USUARIO_H

#include <stdbool.h>

// Nó da lista encadeada que guarda as músicas ouvidas por um usuário
typedef struct NoHistorico {
    int musica_id;
    int quantidade;
    struct NoHistorico* prox;
} NoHistorico;

// Estrutura principal do TAD de Históricos (Vetor de ponteiros para listas)
typedef struct {
    NoHistorico** vetor_usuarios; // Vetor de tamanho 100005
    int capacidade;
} GerenciadorUsuarios;

// Funções do TAD
GerenciadorUsuarios* criar_gerenciador_usuarios(int capacidade);
void usuario_ouve_musica(GerenciadorUsuarios* g, int u, int m);
int quantas_vezes(GerenciadorUsuarios* g, int u, int m);
int musica_favorita_usuario(GerenciadorUsuarios* g, int u);
void esquecer_usuario(GerenciadorUsuarios* g, int u, void (*callback_desconta)(int m, int qtd));
void liberar_gerenciador_usuarios(GerenciadorUsuarios* g);

#endif