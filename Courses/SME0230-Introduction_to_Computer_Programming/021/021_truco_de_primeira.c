/* Exerc ́ıcio 09 - Truco de Primeira

1 Descri ̧c ̃ao
Um colega de classe est ́a pensando em programar um jogo de truco, mas ele n ̃ao sabe como lidar
com o baralho. Sua tarefa  ́e fazer a parte do programa respons ́avel pela valida ̧c ̃ao e categoriza ̧c ̃ao
da m ̃ao de um determinado jogador (isto  ́e, verificar se as 3 cartas dadas s ̃ao v ́alidas e falar qual
a carta mais forte).
Para isso, vejamos como funcionam as cartas de baralho no truco.
1.1 Preparo do Baralho
Para jogar uma partida de truco, o baralho  ́e preparado da seguinte forma: n ̃ao s ̃ao usados os
dois coringas, nem as cartas entre 8 e 10 de todos os naipes. A ordem de “for ̧ca” das cartas, que
difere da mais comum,  ́e a seguinte:

3 > 2 > A > K > J > Q > 7 > 6 > 5 > 4,

em que K  ́e o Rei, J  ́e o Valete e Q  ́e a Dama.
OBS: Para o c ́odigo, considere A = 1, K = 13, J = 11 e Q = 12.
1.2 Ordem da Manilha
No truco h ́a a vira, que  ́e uma carta que fica no centro da mesa para definir a manilha. A
manilha  ́e a carta com valor mais forte da rodada, independentemente da sua posi ̧c ̃ao na ordem
do baralho.
A manilha  ́e dada pelo valor da carta seguinte ao valor da vira. Por exemplo, se a vira for um
7, a manilha ser ́a uma Dama.
Entre as 4 manilhas, a ordem de for ̧ca  ́e dada pela seguinte ordem dos naipes:

Paus > Copas > Espadas > Ouros.

OBS: Para o c ́odigo, considere Paus = 0, Copas = 1, Espadas = 2 e Ouros = 3.
2 Entrada
A entrada consiste de 8 n ́umeros inteiros, representando a m ̃ao de um jogador e a vira. Nas 3
primeiras linhas est ̃ao o par (valor da carta, naipe) de cada carta da m ̃ao do jogador. Na quarta
linha est ́a o par (valor da carta, naipe) da vira.
3 Sa ́ıda
Se a entrada for inv ́alida, ou seja, se tiver cartas repetidas, com valor inv ́alido ou com naipe
inv ́alido, mostrar a mensagem “Entrada invalida.”.
Se a entrada for v ́alida, informar qual carta  ́e a mais forte na m ̃ao do jogador (considerando a
manilha). */

#include <stdio.h>


// 4 5 6 7 12 11 13 1 2 3

int main() {

    int cartas[4][2];

    for (int i = 0; i < 4; i++) {
        // obtem as cartas
        scanf("%d %d", &cartas[i][0], &cartas[i][1]);
        
        // verifica se o naipe é inválido
        if (!(cartas[i][1] >= 0 && cartas[i][1] <= 3)) {
            printf("Entrada invalida.");
            return 0;
        }

        // verifica o valor
        if ((cartas[i][0] < 1 || cartas[i][0] > 13) || (cartas[i][0] >= 8 && cartas[i][0] <= 10)) {
            printf("Entrada invalida.");
            return 0;
        }

        // verifica se já colocou alguma carta igual
        for (int j = 0; j < i; j++) {
            if (cartas[i][0] == cartas[j][0] && cartas[i][1] == cartas[j][1]) {
                printf("Entrada invalida.");
                return 0;
            }
        }
        
    }

    // define a ordem de força do valor
    int forcaValor[10];
    forcaValor[0] = 4;
    forcaValor[1] = 5;
    forcaValor[2] = 6;
    forcaValor[3] = 7;
    forcaValor[4] = 12;
    forcaValor[5] = 11;
    forcaValor[6] = 13;
    forcaValor[7] = 1;
    forcaValor[8] = 2;
    forcaValor[9] = 3;

    // define a ordem de força do naipe
    int forcaNaipe[4];
    forcaNaipe[0] = 3;
    forcaNaipe[1] = 2;
    forcaNaipe[2] = 1;
    forcaNaipe[3] = 0;

    // define a força da manilha
    int manilha[2];

    // define a força do valor da manilha
    for (int i = 0; i < 10; i++) {
        if (forcaValor[i] == cartas[3][0]) {
            if (i == 9) {
                manilha[0] = 0;
            } else {
                manilha[0] = i+1;
            }
        }
    }

    // define a força do naipe da manilha
    for (int i = 0; i < 4; i++) {
        if (forcaNaipe[i] == cartas[3][1]) {
            manilha[1] = i;
        }
    }

    // busca o indice mais forte
    int indiceMaisForte = 0;
    for (int i = 0; i < 3; i++) {
        // situações importantes
        int atualEhManilha = (cartas[i][0] == manilha[0]);
        int indiceEhManilha = (cartas[indiceMaisForte][0] == forcaValor[manilha[0]]);

        if (atualEhManilha && !indiceEhManilha) { // caso a atual seja manilha e o indice não esteja guardando uma manilha

            indiceMaisForte = i; 

        } else if (atualEhManilha && indiceEhManilha) { // caso a atual seja manilha e o indice esteja guardando uma manilha

            int forcaNaipeAtual, forcaNaipeIndice;
            for (int j = 0; j < 4; j++) {
                if (cartas[i][1] == forcaNaipe[j]) forcaNaipeAtual = j;
                if (cartas[indiceMaisForte][1] == forcaNaipe[j]) forcaNaipeIndice = j;
            }
            if (forcaNaipeAtual > forcaNaipeIndice) indiceMaisForte = i; 

        } else if (!atualEhManilha && !indiceEhManilha) { // caso a atual não seja manilha e nem o indice
            int forcaValorAtual, forcaValorChecando;
            
            for (int j = 0; j < 10; j++) {
                if (cartas[i][0] == forcaValor[j]) forcaValorAtual = j;
                if (cartas[indiceMaisForte][0] == forcaValor[j]) forcaValorChecando = j;
            }

            if (forcaValorAtual == forcaValorChecando) { // verifica o valor das duas se é igual para checar pelo naipe
                int forcaNaipeAtual, forcaNaipeChecando;
                for (int j = 0; j < 4; j++) {
                    if (cartas[i][1] == forcaNaipe[j]) forcaNaipeAtual = j;
                    if (cartas[indiceMaisForte][0] == forcaNaipe[j]) forcaNaipeChecando = j;
                }
                if (forcaNaipeAtual > forcaNaipeChecando) indiceMaisForte = i;
            } else { // se não, checa pela força
                if (forcaValorAtual > forcaValorChecando) indiceMaisForte = i;
            }
            
            
        }
    }

    // mostra a carta mais forte
    printf("%d %d", cartas[indiceMaisForte][0], cartas[indiceMaisForte][1]);
    


    return 0;
}