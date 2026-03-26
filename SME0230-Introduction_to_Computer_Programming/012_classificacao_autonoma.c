/* 1 Descrição
Você foi selecionado para automatizar a classificação dos times do Tusquinha. Para isso, faça um
programa em C que, dada a pontuação do time e quantas partidas perdeu, mostre automaticamente
a classificação dele.
Os times são classificados da seguinte forma:
 Se tem uma pontuação maior que 200 ou perdeu menos de 2 partidas, ele é um time “Incrivel”.
 Se tem uma pontuação maior que 150 ou perdeu menos de 3 partidas, ele é um time “Muito
Bom”.
 Se tem uma pontuação maior que 100 ou perdeu menos de 5 partidas, ele é um time “Bom”.
 Caso contrário, ele é um time “Decente”.
2 Entrada
A entrada consiste de dois números inteiros, respectivamente a pontuação do time e o número
de derrotas do time.
3 Saída
Você deve mostrar qual a classificação do respectivo time ou se a entrada era inválida. */

#include <stdio.h>

int main() {

    // criação de variáveis
    int points, loses;

    // recebimento das informações
    //printf("Entre com a pontuação da equipe e a quantidade de derrotas, respectivamente");
    scanf("%d %d", &points, &loses);

    // validade dos dados
    if (points < 0 || loses < 0) {
        printf("Entrada invalida");
    } else {
        // verificar o resultado
        if (points > 200 || loses < 2) {
            printf("Incrivel");
        } else if (points > 150 || loses < 3) {
            printf("Muito Bom");
        } else if (points > 100 || loses < 5) {
            printf("Bom");
        } else {
            printf("Decente");
        }
    }

    return (0);
}