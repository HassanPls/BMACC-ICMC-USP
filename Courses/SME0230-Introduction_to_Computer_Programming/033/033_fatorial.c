// Programa que le um numero inteiro
// positivo e calcula seu fatorial.

#include <stdio.h>

// Funcao recursiva que recebe um inteiro
// positivo n e devolve o fatorial de n. 

long long int fatorial_recursivo(int n) {
  long long int resultado;
  
  if (n == 0) {
    return(1);
  }
  
  resultado = n * fatorial_recursivo(n-1);

  return(resultado);
}

// Funcao principal.
int main() {
  int numero;
  long long int fat;
  
  // Pede e le um numero inteiro positivo.
  do {
    printf("Digite um numero para calcular seu fatorial: ");
    scanf("%d", &numero);
  } while (numero < 0);

  // Chama a funcao para calcular o fatorial.
  fat = fatorial_recursivo(numero);

  // Mostra o valor do fatorial.
  printf("%d! = %lld\n", numero, fat);
  
  return(0);
}