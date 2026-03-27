/* 1 Descrição

Ao estudar estruturas de repetição em linguagem C, Joãozinho decidiu colocá-las em prá-
tica por meio da geração de padrões numéricos organizados em matrizes. Em particular,

ele explorou variações da matriz identidade, nas quais os elementos iguais a 1 não se
encontram necessariamente na diagonal principal, mas sim em uma diagonal deslocada
acima ou abaixo dela. Esse deslocamento indica quantas posições a diagonal de 1’s é
movida para cima ou para baixo em relação à diagonal principal, enquanto os demais
elementos da matriz permanecem iguais a 0.
Por exemplo, para ordem igual a 4 e deslocamento igual a 1, obtém-se a seguinte
matriz:

0 1 0 0
0 0 1 0
0 0 0 1
0 0 0 0

Já para ordem igual a 4 e deslocamento igual a -2, obtém-se a seguinte matriz:

0 0 0 0
0 0 0 0
1 0 0 0
0 1 0 0

Com isso, Joãozinho escreveu um programa em C que lê dois números inteiros, cor-
respondentes à ordem de uma matriz quadrada e ao deslocamento desejado, e imprime a

matriz de acordo com a regra descrita acima. No entanto, o código contém erros.
Corrija o código de Joãozinho.

3 Entrada
A entrada consiste em dois números inteiros, correspondentes, respectivamente, à ordem
da matriz quadrada e ao deslocamento desejado para a diagonal de 1’s.
4 Saída
Você deve imprimir a matriz resultante seguindo as regras de deslocamento. Caso as
entradas não façam sentido, a mensagem “valor invalido” deve ser mostrada. */

#include <stdio.h>

int main() {
  int ordem, deslocamento;
  
  scanf("%d %d", &ordem, &deslocamento);
  
  if (ordem <= 0 || deslocamento >= ordem || deslocamento <= -ordem) {
    printf("valor invalido");
  } else {
    for (int i = 1; i <= ordem; i++) {
        for (int j = 1; j <= ordem; j++) {
            if (i + deslocamento == j) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
  }
  return(0);
}