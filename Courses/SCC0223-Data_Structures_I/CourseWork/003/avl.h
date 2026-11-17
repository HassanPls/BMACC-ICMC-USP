#ifndef AVL_H
#define AVL_H

#include <stdbool.h>

// Nó da Árvore AVL Aumentada para o Ranking
typedef struct NoAVL {
    int musica_id;
    int total;
    int altura;
    int subtree_size;        // Quantidade de nós na subárvore (essencial para POSICAO e KESIMA)
    struct NoAVL* esq;
    struct NoAVL* dir;
} NoAVL;

// Estrutura auxiliar para acesso direto O(1) às músicas
typedef struct {
    NoAVL** vetor_ponteiros; // Mapeia musica_id -> NoAVL* (tamanho 100005)
    NoAVL* raiz;
    int total_musicas_ativas;
} RankingAVL;

// Funções do TAD
RankingAVL* criar_ranking(int max_musicas);
NoAVL* inserir_ranking(NoAVL* raiz, int musica_id, int total, NoAVL** vetor_ptr);
NoAVL* remover_ranking(NoAVL* raiz, int musica_id, NoAVL** vetor_ptr);
NoAVL* buscar_musica(NoAVL* raiz, int musica_id);

// Consultas avançadas de O(log M)
int obter_posicao(NoAVL* raiz, int musica_id, int total);
int obter_kesima(NoAVL* raiz, int k);
int contar_faixa(NoAVL* raiz, int a, int b);

void liberar_ranking(NoAVL* raiz);

#endif