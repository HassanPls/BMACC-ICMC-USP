/* Exerc ́ıcio 8 - Bit de Paridade e Carga Util  ́

1 Descri ̧c ̃ao
Quando computadores enviam dados, interferˆencias podem acidentalmente transformar um 0
em 1 no caminho. Para descobrir se a mensagem chegou inteira ou se foi corrompida, usamos uma
regra simples de verifica ̧c ̃ao chamada Paridade  ́Impar. Funciona assim:
• O transmissor pega a mensagem real de tamanho N (chamada de Carga Util) e adiciona 1  ́
bit extra no final (o Bit de Paridade), enviando um total de N + 1 bits.
• Esse bit extra  ́e ajustado para garantir que a quantidade total de n ́umeros 1 na sequˆencia
inteira seja sempre um n ́umero  ́ımpar.
• Se o destino receber a sequˆencia e a contagem total de bits 1 for par, ele saber ́a imediatamente
que houve um erro na transmiss ̃ao.
Escreva um programa em C que leia o tamanho N de uma mensagem. Ele deve ler os N + 1
bits recebidos (0s e 1s), armazenando essa sequˆencia completa em um vetor, e seguir os passos:
1. Se a mensagem for v ́alida: Imprima a carga  ́util.
2. Se a mensagem for corrompida: Descarte os dados e imprima a mensagem de erro
apropriada.
2 Entrada
A primeira linha toma um n ́umero inteiro N representando o tamanho da carga  ́util original. Se

N > 0, haver ́a na mesma linha (ou na seguinte) N + 1 n ́umeros inteiros separados por espa ̧cos, rep-
resentando os bits da mensagem mais o bit de paridade final. O valor de cada bit ser ́a estritamente

0 ou 1. Se N ≤ 0, n ̃ao haver ́a leitura de bits adicionais.
3 Sa ́ıda
Se o tamanho N for menor ou igual a zero, imprima: Tamanho invalido. seguido de uma
quebra de linha.
Se a mensagem for lida e estiver  ́ıntegra, imprima: Carga util: seguido de um espa ̧co e os N
bits da carga  ́util separados por espa ̧cos, seguido de uma quebra de linha.
Se a mensagem for lida e estiver corrompida, imprima exatamente: Quadro corrompido.
seguido de uma quebra de linha. */

#include <stdio.h>

int main() {

    // criação de variaveis
    int n, vetN[50], paridade;

    //leitura e verificação do tamanho do bit
    scanf("%d", &n);
    if (n <= 0) {
        printf("Tamanho invalido.");
        return 0;
    }

    //leitura do bit em si
    for (int i = 0; i < n+1; i++) {
        scanf("%d", &vetN[i]);
        if (vetN[i] != 1 & vetN[i] != 0) return 0;
    }
    
    // contagem da paridade
    for (int i = 0; i < 50; i++) {
        if (vetN[i] == 1) paridade++;
    }
    
    // verificação da validade da paridade
    if (!(paridade % 2)) {
        printf("Carga util:");
        for (int i = 0; i < n; i++) {
            printf(" %d", vetN[i]);
        }
    } else {
        printf("Quadro corrompido.");
    }


    return 0;
}