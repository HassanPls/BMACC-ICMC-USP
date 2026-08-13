// --------------------------------------------
// Programa que le dois numeros reais e calcula
// a media aritmetica entre esses numeros (essa
// media representa a media em uma disciplina).
// Se a media for maior ou igual a 5, diz que a
// pessoa passou. Caso contrario, diz que nao.
// --------------------------------------------

#include <stdio.h>

int main() {
  float num1, num2, media;

  // Pede para digitar 2 numeros e os armazena em num1 e num2
  printf("=== Calculadora de media aritmetica ===\n\n");
  printf("Digite dois numeros: ");
  scanf("%f %f", &num1, &num2);

  // Calcula a media dos dois numeros digitados
  media = (num1 + num2)/2;
  
  // Mostra a media calculada
  printf("Sua media eh %f\n", media);

  // Verifica se passou ou reprovou
  if (media >= 5) {
    printf("Voce passou! :)\n");
    printf("Parabens\n");
  }
  else {
    printf("Nao foi dessa vez :(\n");
    printf("Que pena!\n");       
  }

  return(0);
}