// Programa que le dois numeros inteiros n e k e calcula
// a combinacao de n, k a k.

#include <stdio.h>

// Funcao que recebe um numero e
// devolve seu fatorial.

int fatorial(int numero) {
  int resultado,i;

  resultado = 1;
  for (i = numero; i > 1; i--) {
    resultado = resultado * i;
  }

  return(resultado);  
}

// Funcao principal.

int main() {
  int n, k, combinacao;


  // Le os numeros n e k, com n >= 0, k >= 0 e n >= k.
  do {
    printf("Digite dois numeros inteiros n e k, para calcular a combinacao de n, k a k: ");
    scanf("%d %d", &n, &k);
  } while((n < 0) || (k < 0) || (k > n));

  // Calcula a combinacao de n, k a k.
  combinacao = fatorial(n) / (fatorial(k) * fatorial(n-k));

  // Mostra o valor da combinacao.
  printf("A combinacao eh: %d\n", combinacao);
  
  return(0);
}
