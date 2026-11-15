#include <stdio.h>
#include <stdlib.h>
#include "deck.h"

// Cria um novo baralho com n cartas ordenadas de 1 a n (topo ao fundo)
Deck* criar_baralho(int n) {
    Deck* d = (Deck*) malloc(sizeof(Deck));
    if (!d) return NULL;

    d->n = n;
    d->direcao = 1; // 1 significa sentido normal (next é para baixo/fundo)
    d->top = NULL;

    if (n <= 0) return d;

    Node* primeiro = NULL;
    Node* anterior = NULL;

    // Cria os nós de 1 até n
    for (int i = 1; i <= n; i++) {
        Node* novo = (Node*) malloc(sizeof(Node));
        novo->label = i;
        novo->prev = NULL;
        novo->next = NULL;

        // Guarda o ponteiro no vetor auxiliar de acesso direto O(1)
        d->vetor_cartas[i] = novo;

        if (i == 1) {
            primeiro = novo;
            d->top = novo;
        } else {
            anterior->next = novo;
            novo->prev = anterior;
        }
        anterior = novo;
    }

    // Fecha o ciclo da lista circular (conecta o último ao primeiro e vice-versa)
    anterior->next = primeiro;
    primeiro->prev = anterior;

    return d;
}

// Libera toda a memória alocada pelo baralho
void destruir_baralho(Deck* d) {
    if (!d) return;

    // Liberta cada nó individualmente usando o vetor de acesso direto,
    // evitando qualquer travessia por ponteiros circulares corrompidos.
    for (int i = 1; i <= d->n; i++) {
        if (d->vetor_cartas[i]) {
            free(d->vetor_cartas[i]);
            d->vetor_cartas[i] = NULL;
        }
    }

    // Liberta a estrutura principal do baralho
    free(d);
}

void sobe(Deck* d, int x) {
    if (!d || d->n <= 1) return;

    Node* alvo = d->vetor_cartas[x];
    if (!alvo || alvo == d->top) {
        // Se a carta já está no topo, nada muda estruturalmente (mas entra no histórico)
        return;
    }

    // Retirar o nó 'alvo' da sua posição atual (isolar o nó)
    alvo->prev->next = alvo->next;
    alvo->next->prev = alvo->prev;

    // Inserir o nó imediatamente antes do topo atual
    Node* topo_atual = d->top;
    Node* antes_do_topo = topo_atual->prev;

    antes_do_topo->next = alvo;
    alvo->prev = antes_do_topo;

    alvo->next = topo_atual;
    topo_atual->prev = alvo;

    // Atualizar o ponteiro do topo para a nova carta
    d->top = alvo;
}

// Corta o baralho logo acima da carta x: x fica no topo e as anteriores vão para o fundo
void cortar(Deck* d, int x) {
    if (!d || d->n <= 1) return;

    Node* alvo = d->vetor_cartas[x];
    if (!alvo || alvo == d->top) {
        // Cortar na carta que já está no topo não altera o baralho
        return;
    }

    // Numa lista circular, alterar o topo para a carta 'x' redefine 
    // instantaneamente o início e o fim do baralho em O(1)
    d->top = alvo;
}

// Inverte o baralho inteiro em O(1) alterando a direção de leitura
void vira(Deck* d) {
    if (!d || d->n <= 1) return;
    // O fundo passa a ser o novo topo
    d->top = (d->direcao == 1) ? d->top->prev : d->top->next;
    // Inverte o sentido de leitura
    d->direcao *= -1;
}

// Inverte apenas as k cartas do topo
void viratopo(Deck* d, int k) {
    if (!d || k <= 1 || k > d->n) return;

    Node** bloco = (Node**) malloc(k * sizeof(Node*));
    if (!bloco) return;

    Node* atual = d->top;
    int passo = (d->direcao == 1) ? 1 : -1;

    // Coleta os nós do topo na ordem visual atual
    for (int i = 0; i < k; i++) {
        bloco[i] = atual;
        atual = (passo == 1) ? atual->next : atual->prev;
    }

    // Inverte os rótulos (labels) simetricamente no bloco
    for (int i = 0; i < k / 2; i++) {
        int temp = bloco[i]->label;
        bloco[i]->label = bloco[k - 1 - i]->label;
        bloco[k - 1 - i]->label = temp;

        // Atualiza o vetor de acesso direto O(1) para refletir a troca
        d->vetor_cartas[bloco[i]->label] = bloco[i];
        d->vetor_cartas[bloco[k - 1 - i]->label] = bloco[k - 1 - i];
    }

    free(bloco);
}

// Retorna o rótulo da carta na posição p (1 é o topo)
int carta_na_posicao(Deck* d, int p) {
    if (!d || p < 1 || p > d->n) return -1;

    Node* atual = d->top;
    
    // Caminha p - 1 passos a partir do topo respeitando a direção atual
    for (int i = 1; i < p; i++) {
        atual = (d->direcao == 1) ? atual->next : atual->prev;
    }

    return atual->label;
}

// Retorna a posição (1-based) da carta x
int posicao_da_carta(Deck* d, int x) {
    if (!d || x < 1 || x > d->n) return -1;

    Node* alvo = d->vetor_cartas[x];
    Node* atual = d->top;
    int pos = 1;

    // Caminha a partir do topo até encontrar o nó da carta x
    while (atual != alvo) {
        atual = (d->direcao == 1) ? atual->next : atual->prev;
        pos++;
    }

    return pos;
}

// Imprime do topo ao fundo os rótulos das cartas, separados por um espaço
void mostra_baralho(Deck* d) {
    if (!d || d->n <= 0) return;

    // O limite do enunciado para a quantidade de cartas no MOSTRA é 200
    int limite = (d->n < 200) ? d->n : 200; 

    Node* atual = d->top;
    for (int i = 0; i < limite; i++) {
        printf("%d%s", atual->label, (i == limite - 1) ? "" : " ");
        atual = (d->direcao == 1) ? atual->next : atual->prev;
    }
    printf("\n");
}

Historico* criar_historico(void) {
    Historico* h = (Historico*) malloc(sizeof(Historico));
    if (!h) return NULL;
    h->inicio = 0;
    h->qtd = 0;
    return h;
}

void destruir_historico(Historico* h) {
    if (h) free(h);
}

void limpa_historico(Historico* h) {
    if (h) {
        h->inicio = 0;
        h->qtd = 0;
    }
}

// Registra uma operação. Se exceder 100, remove a mais antiga.
void registrar_op(Historico* h, Operacao op) {
    if (!h) return;

    int pos;
    if (h->qtd < 100) {
        pos = (h->inicio + h->qtd) % 100;
        h->qtd++;
    } else {
        // Se o buffer está cheio, sobrescreve a mais antiga e avança o início
        pos = h->inicio;
        h->inicio = (h->inicio + 1) % 100;
    }

    h->ops[pos] = op;
}

// Desfaz a operação mais recente do histórico
int desfez_op(Historico* h, Deck* d) {
    if (!h || !d || h->qtd == 0) return 0; // Histórico vazio: nada a fazer

    int pos_topo = (h->inicio + h->qtd - 1) % 100;
    Operacao op = h->ops[pos_topo];
    h->qtd--; // Remove do histórico

    switch (op.tipo) {
        case OP_VIRA:
            // Desfazer VIRA é apenas inverter novamente
            vira(d);
            break;

        case OP_VIRATOPO:
            // Desfazer VIRATOPO k é aplicar VIRATOPO k novamente nas mesmas k cartas
            viratopo(d, op.x);
            break;

        case OP_CORTA:
            // Restaura o topo antigo que estava salvo no registro
            d->top = op.old_top;
            break;

        case OP_SOBE: {
            // Desfazer SOBE x: retirar x do topo e reinserir no seu antigo lugar
            if (d->top->label == op.x && op.prev_node != NULL) {
                Node* alvo = d->top;
                
                // Desconecta do topo atual
                d->top = (d->direcao == 1) ? alvo->next : alvo->prev;

                // Restaura o ciclo do baralho sem o 'alvo'
                alvo->prev->next = alvo->next;
                alvo->next->prev = alvo->prev;

                // Insere 'alvo' de volta logo após 'prev_node'
                Node* antigo_prox = op.prev_node->next;

                op.prev_node->next = alvo;
                alvo->prev = op.prev_node;

                alvo->next = antigo_prox;
                antigo_prox->prev = alvo;
            }
            break;
        }
    }

    return 1;
}