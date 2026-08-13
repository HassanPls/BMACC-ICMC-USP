// Programa que le dois numeros e
// faz a operacao escolhida pelo(a)
// usuario(a). Elas podem ser soma,
// subtracao, multiplicacao ou divisao.
// Usa switch-case para descobrir qual
// operacao foi escolhida.

// Roteiro:
//
// Menu =
// 1. Adicao (mais)
// 2. Subtracao (menos)
// 3. Multiplicacao (vezes)
// 4. Divisao (dividir)
//
// 1. Criar 4 variaveis (1 para a operacao,
//    2 para os numeros e 1 para o resultado).
// 2. Perguntar qual operacao quer fazer.
// 3. Ler a operacao digitada (seguindo o menu
//    acima) e armazenar em uma variavel.
// 4. Pedir para digitar 2 numeros.
// 5. Ler os numeros digitados e armazenar nas
//    variaveis.
// 6. Verificar qual operacao foi escolhida e
//    fazer a operacao.
// 7. Mostrar o resultado da operacao.

#include <stdio.h>

int main() {

  // 1. Criar 4 variaveis (1 para a operacao,
  //    2 para os numeros e 1 para o resultado).
  int operacao;
  float num1, num2, resultado;
  
  // 2. Perguntar qual operacao quer fazer.
  printf("Digite o numero correspondente a operacao que voce quer fazer:\n");
  printf("1. Adicao (mais)\n2. Subtracao (menos)\n3. Multiplicacao (vezes)\n4. Divisao (dividir)\n");
  
  // 3. Ler a operacao digitada (seguindo o menu
  //    acima) e armazenar em uma variavel.
  scanf("%d", &operacao);

  // Verifica qual operacao foi escolhida
  switch(operacao) {

  // Se escolheu adicao, pede os numeros, le os numeros,
  // faz a adicao e mostra o resultado.
  case 1: 
    printf("Digite os 2 numeros para fazer a adicao: ");
    scanf("%f %f", &num1, &num2);
    resultado = num1 + num2;
    printf("%f + %f = %f\n", num1, num2, resultado);
    break;

  // Se escolheu subtracao, pede os numeros, le os numeros,
  // faz a subtracao e mostra o resultado.  
  case 2:
    printf("Digite os 2 numeros para fazer a subtracao: ");
    scanf("%f %f", &num1, &num2);
    resultado = num1 - num2;
    printf("%f - %f = %f\n", num1, num2, resultado);
    break;

  // Se escolheu multiplicacao, pede os numeros, le os numeros,
  // faz a multiplicacao e mostra o resultado.  
  case 3:
    printf("Digite os 2 numeros para fazer a multiplicacao: ");
    scanf("%f %f", &num1, &num2);
    resultado = num1 * num2;
    printf("%f * %f = %f\n", num1, num2, resultado);
    break;

  // Se escolheu divisao, pede os numeros e le os numeros.
  // Caso o segundo numero seja 0, mostra uma mensagem de
  // erro. Caso contrario, faz a divisao e mostra o resultado. 
  case 4:
    printf("Digite os 2 numeros para fazer a divisao: ");
    scanf("%f %f", &num1, &num2);

    if (num2 == 0) {
      printf("Nao da para dividir por 0!\n");
    }
    else {
      resultado = num1 / num2;
      printf("%f / %f = %f\n", num1, num2, resultado);
    }
    break;

  // Se digitou um numero que nao esta entre 1 e 4,
  // mostra uma mensagem de erro. 
  default:
    printf("Operacao invalida, booo\n");
  }

  return(0);
}