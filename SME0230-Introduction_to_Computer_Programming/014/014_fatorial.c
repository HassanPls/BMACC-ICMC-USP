// Programa que calcula o fatorial
// de um numero.

// Roteiro:
// 1. Criar uma variavel para o numero n, uma para
//    o fatorial e outra para contar.
// 2. Pedir o numero para calcular o fatorial.
// 3. Ler o numero.
// 4. Comecar com o valor do fatorial em 1.
// 5. Comecar com o contador em n.
// 6. Enquanto o contador nao chegar em 1, repete:
// 6.1. Multiplicar o fatorial pelo contador.
// 6.2. Atualizar o contador diminuindo seu valor em 1.
// 7. Mostrar o resultado do fatorial

#include <stdio.h>

int main() {

  // 1. Criar uma variavel para o numero n, uma para
  //    o fatorial e outra para contar. Todas essas
  //    variaveis seriam inteiras, mas como o valor do
  //    fatorial pode ser muito grande, usamos para
  //    ele o tipo "long long int", que armazena
  //    inteiros maiores.
  
  int n, fator_decrescente;
  long long int fatorial;

  // 2. Pedir o numero para calcular o fatorial.
  
  printf("Digite um numero (maior ou igual a 0): ");

  // 3. Ler o numero.

  scanf("%d", &n);

  // Verifica se o numero digitado eh negativo.
  // Enquanto for, pede para digitar e le novamente.
  // Quando este laco "while" termina, o valor do
  // numero eh maior ou igual a 0.
  
  while (n < 0) {
    printf("O numero nao pode ser negativo! Digite novamente: ");
    scanf("%d", &n);
  }

  // 4. Comecar com o valor do fatorial em 1.

  fatorial = 1;

  // 5. Comecar com o contador em n (primeiro bloco do "for",
  //    antes do primeiro ";", que eh executado antes do laco).
  // 6. Enquanto o contador nao chegar em 1 (condicao do "for"
  //    entre os dois ";"), repete:
  
  for (fator_decrescente = n; fator_decrescente > 1; fator_decrescente--) {
    // 6.1. Multiplicar o fatorial pelo contador.
    fatorial = fatorial * fator_decrescente;

    // 6.2. Atualiza o contador diminuindo seu valor em 1
    //      (terceiro bloco do "for", depois do segundo ";",
    //      que eh executado em toda iteracao, depois de todos
    //      os comandos do corpo do "for" e antes de verificar
    //      novamente se a condicao eh satisfeita).

  }

  // 7. Mostrar o resultado do fatorial
  printf("%d! = %lld\n", n, fatorial);
  
  return(0);
}