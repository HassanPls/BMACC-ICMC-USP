// Programa que le 3 numeros positivos e
// verifica se eles correspondem a lados
// de um triangulo.

// Roteiro:
//
// 1. Criar 3 variaveis, uma para cada lado.
// 2. Pedir para digitar o comprimento dos lados.
// 3. Ler e armazenar os lados nas variaveis.
// 4. Verificar se lados formam um triangulo.
// 5. Dizer se os lados formam ou nao um triangulo.
//    Caso nao formem, mostrar um motivo.

#include <stdio.h>

int main() {
  
  // 1. Criar 3 variaveis, uma para cada lado.
  float lado1, lado2, lado3;
  
  // 2. Pedir para digitar o comprimento dos lados.
  printf("Digite os 3 lados de um triangulo: ");
  
  // 3. Ler e armazenar os lados nas variaveis.
  scanf("%f %f %f", &lado1, &lado2, &lado3);
  
  // 4. Verificar se lados formam um triangulo
  // 5. Dizer se os lados formam ou nao um triangulo.
  //    Caso nao formem, mostrar um motivo.
  if (lado1 + lado2 <= lado3) {
    printf("NAO eh um triangulo, porque 1o lado + 2o lado = %f, que eh menor ou igual ao 3o lado (%f)\n", lado1+lado2, lado3);
  }
  else {
    if (lado1 + lado3 <= lado2) {
      printf("NAO eh um triangulo, porque 1o lado + 3o lado = %f, que eh menor ou igual ao 2o lado (%f)\n", lado1+lado3, lado2);
    }
    else {
      if (lado2 + lado3 <= lado1) {
	printf("NAO eh um triangulo, porque 2o lado + 3o lado = %f, que eh menor ou igual ao 1o lado (%f)\n", lado2+lado3, lado1);
      }
      else {
	printf("Eh um triangulo\n");
      }
    }
  }
  
  return(0);
}