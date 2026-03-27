/* 1 Descrição
Em teoria dos números, a sequência de Collatz é definida a partir de um número inteiro
positivo e construída por meio de uma regra simples: se o número for par, divide-se por
2; se for ímpar, multiplica-se por 3 e soma-se 1. Esse processo é repetido sucessivamente,

gerando uma sequência de valores. Apesar da simplicidade da regra, ainda não foi de-
monstrado formalmente que toda sequência obtida dessa forma eventualmente atinge o

valor 1, o que constitui o conhecido problema ou conjectura de Collatz.
Por exemplo, iniciando com o número 6, obtém-se a sequência: 6 → 3 → 10 → 5 →
16 → 8 → 4 → 2 → 1, na qual são necessários 8 passos para alcançar o valor 1.
Escreva um programa em C que leia um número inteiro positivo, imprima os termos
da sequência de Collatz a partir desse valor inicial e determine a quantidade de passos
necessários até que o valor 1 seja atingido.
2 Entrada
A entrada deve ser um número inteiro positivo.
3 Saída
A primeira linha deve mostrar os termos da sequência, separados por vírgulas e delimitados
por parênteses; a quantidade de passos deve ser mostrada na segunda linha. Se o número
for menor do que ou igual a zero, a mensagem “valor invalido” deve ser mostrada. */

#include <stdio.h>

int main() {

    int num, seq = 0;
    
    scanf("%d", &num);

    if (num <= 0) {
        printf("valor invalido");
        return 0;
    }
    
    printf("(");
    for (int i = 1; num > 1; i++) {
        printf("%d", num);

        if (num % 2 == 0) {
            num = num/2;
        } else {
            num = (num * 3) + 1;
        }

        printf(", ");
        seq = i;
    }
    
    printf("1)\n");

    printf("%d", seq);
    
    return 0;
}