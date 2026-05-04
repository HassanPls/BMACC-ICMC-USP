/*
 * Nome: Pedro Luiz Mariano Vogado Filho - Número USP: 18193952
 * Nome: Lorenzo Zoculin de Alcantara - Número USP: 18119155
 */

#include <stdio.h>

#define MAX_VIDA 20
#define TOTAL_CARTAS 44

int main()
{
    int masmorra[200][2];          // Cartas na masmorra (200 para poder pular a sala)
    int pontos_vida = MAX_VIDA;    // Quantidade de vida do player
    int arma_valor = 0;            // Forca da arma
    int arma_limite_monstro = 15;  // Limite que a arma pode enfrentar
    int jogo_ativo = 1;            // Controle para o jogo continuar rodando
    int indice_topo = 0;           // Lugar em que a masmorra está no indice do vetor masmorra
    int semente;                   // Indice para embaralhar
    int sala[4][2];                // As 4 cartas disponíveis na mesa
    int cartas_na_sala = 0;        // Quantas cartas estão atualmente na sala
    int escolheu_evitar = 0;       // Para controlar se a sala atual foi evitada
    int sala_anterior_evitada = 0; // Para impedir evitar duas seguidas

    int total_atual_deck = TOTAL_CARTAS;

    // --- PREPARAÇÃO DO BARALHO ---
    int k = 0;
    for (int naipe = 0; naipe <= 1; naipe++)
    {
        for (int valor = 2; valor <= 14; valor++)
        {
            masmorra[k][0] = valor;
            masmorra[k][1] = naipe;
            k++;
        }
    }
    for (int naipe = 2; naipe <= 3; naipe++)
    {
        for (int valor = 2; valor <= 10; valor++)
        {
            masmorra[k][0] = valor;
            masmorra[k][1] = naipe;
            k++;
        }
    }

    // --- EMBARALHAMENTO MANUAL ---
    printf("Digite um numero inteiro para embaralhar a Masmorra: ");
    scanf("%d", &semente); // O usuário fornece a "aleatoriedade"

    // Realiza uma série de trocas fixas baseadas no número digitado
    for (int i = 0; i < TOTAL_CARTAS; i++)
    {
        // Calcula um índice de troca pseudo-aleatório manualmente
        int j = (semente + i * 7) % TOTAL_CARTAS;

        // Troca os valores entre a posição i e j
        int temp_valor = masmorra[i][0];
        int temp_naipe = masmorra[i][1];

        masmorra[i][0] = masmorra[j][0];
        masmorra[i][1] = masmorra[j][1];

        masmorra[j][0] = temp_valor;
        masmorra[j][1] = temp_naipe;
    }

    printf("Masmorra preparada!\n");

    while (jogo_ativo && pontos_vida > 0)
    {
        // --- PREENCHER A SALA ---
        // A sala deve ter 4 cartas. Se sobrou 1 da rodada anterior, pegamos mais 3.
        while (cartas_na_sala < 4 && indice_topo < total_atual_deck)
        {
            sala[cartas_na_sala][0] = masmorra[indice_topo][0];
            sala[cartas_na_sala][1] = masmorra[indice_topo][1];
            cartas_na_sala++;
            indice_topo++;
        }

        // Se a sala não tem 4 cartas e a masmorra acabou, o jogo termina
        if (cartas_na_sala == 0 && indice_topo >= total_atual_deck)
        {
            printf("Voce atravessou a masmorra e venceu!\n");
            jogo_ativo = 0;
        }
        else
        {
            // --- EXIBIÇÃO DA MESA ---
            printf("\n--- MESA ---\n");
            printf("Vida: %d | Arma: %d (Limite: < %d)\n", pontos_vida, arma_valor, arma_limite_monstro);

            for (int i = 0; i < cartas_na_sala; i++)
            {
                printf("Carta %d: ", i + 1);

                // Se o valor for 0, significa que a carta já foi resolvida neste turno
                if (sala[i][0] == 0)
                {
                    printf("[ USADA / DERROTADA ]\n");
                }
                else
                {
                    printf("Valor %d | Naipe ", sala[i][0]);
                    if (sala[i][1] == 0)
                        printf("(Paus - Monstro)\n");
                    else if (sala[i][1] == 1)
                        printf("(Espadas - Monstro)\n");
                    else if (sala[i][1] == 2)
                        printf("(Ouros - Arma)\n");
                    else if (sala[i][1] == 3)
                        printf("(Copas - Pocao)\n");
                }
            }

            // --- DECISÃO: EVITAR OU ENFRENTAR ---
            if (sala_anterior_evitada == 0)
            {
                do
                {
                    printf("\nDeseja evitar esta sala? (1-Sim, 0-Nao): ");
                    scanf("%d", &escolheu_evitar);
                } while (escolheu_evitar != 1 && escolheu_evitar != 0);
            }
            else
            {
                printf("\nVoce nao pode evitar esta sala (evitou a anterior).\n");
                escolheu_evitar = 0;
            }

            if (escolheu_evitar == 1)
            {
                // Move as 4 cartas da sala para o fim da masmorra
                for (int i = 0; i < cartas_na_sala; i++)
                {
                    masmorra[total_atual_deck][0] = sala[i][0];
                    masmorra[total_atual_deck][1] = sala[i][1];
                    total_atual_deck++; // Índice de quantidade de cartas
                }

                cartas_na_sala = 0;        // Sala limpa para o próximo turno
                sala_anterior_evitada = 1; // Não pode evitar duas seguidas
            }
            else
            {
                // Se enfrentar: o jogador deve resolver 3 das 4 cartas

                int usou_pocao_nesta_sala = 0;
                sala_anterior_evitada = 0;
                int resolvidas = 0;
                int escolha;

                while (resolvidas < 3 && pontos_vida > 0)
                {
                    printf("\nEscolha uma carta para enfrentar (1-4): ");
                    scanf("%d", &escolha);

                    // Validação: a escolha deve ser entre 1 e 4 E a carta não pode ter sido usada
                    if (escolha >= 1 && escolha <= 4 && sala[escolha - 1][0] != 0)
                    {
                        int v_carta = sala[escolha - 1][0];
                        int n_carta = sala[escolha - 1][1];

                        // --- LÓGICA DE RESOLUÇÃO DA CARTA ---

                        // MONSTRO (Paus=0, Espadas=1)
                        if (n_carta == 0 || n_carta == 1)
                        {
                            printf("Voce enfrentou um Monstro de valor %d!\n", v_carta);
                            // Se tiver arma e o monstro for menor que o último derrotado
                            if (arma_valor > 0 && v_carta < arma_limite_monstro)
                            {
                                int dano = v_carta - arma_valor;
                                if (dano > 0)
                                    pontos_vida -= dano;
                                arma_limite_monstro = v_carta; // Nova restrição da arma
                            }
                            else
                            {
                                pontos_vida -= v_carta; // Sem arma ou monstro muito forte
                            }
                        }
                        // ARMA (Ouros=2)
                        else if (n_carta == 2)
                        {
                            printf("Voce equipou uma Arma de valor %d!\n", v_carta);
                            arma_valor = v_carta;
                            arma_limite_monstro = 15; // Reset do limite (pode enfrentar qualquer um)
                        }
                        // POÇÃO (Copas=3)
                        else if (n_carta == 3)
                        {
                            if (usou_pocao_nesta_sala == 0)
                            {
                                printf("Voce usou uma Pocao de valor %d!\n", v_carta);
                                pontos_vida += v_carta;
                                usou_pocao_nesta_sala = 1;
                                if (pontos_vida > MAX_VIDA)
                                    pontos_vida = MAX_VIDA;
                            }
                            else
                            {
                                printf("Voce ja usou uma Pocao nessa sala!");
                            }
                        }

                        // Marcar a carta como usada (valor 0)
                        sala[escolha - 1][0] = 0;
                        resolvidas++;
                        if (pontos_vida > 0)
                            printf("Vida atual: %d\n", pontos_vida);
                    }
                    else
                    {
                        printf("Escolha invalida ou carta ja utilizada! Tente novamente.\n");
                    }
                }

                // REORGANIZAR A SOBRA
                int indice_sobra = -1;
                for (int i = 0; i < 4; i++)
                {
                    if (sala[i][0] != 0)
                    {
                        indice_sobra = i;
                    }
                }

                if (indice_sobra != -1)
                {
                    sala[0][0] = sala[indice_sobra][0];
                    sala[0][1] = sala[indice_sobra][1];
                    cartas_na_sala = 1; // Sobrou 1 para o próximo preenchimento
                }
                else
                {
                    cartas_na_sala = 0;
                }
            }
        }

        if (pontos_vida <= 0)
        {
            printf("Seus pontos de vida chegaram a 0. Voce perdeu!\n");
            jogo_ativo = 0;
        }
    }

    return 0;
}