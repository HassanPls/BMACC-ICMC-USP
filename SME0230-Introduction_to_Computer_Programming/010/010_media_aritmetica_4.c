// Programa que le 4 numeros e calcula
// a media aritmetica dos 4 numeros.

// Roteiro:
//
// 1. Criar 4 variaveis para armazenar os 4 numeros e 
//    uma para armazenar a media.
// 2. Pedir para a pessoa digitar os 4 numeros.
// 3. Ler os 4 numeros e armazenar nas 4 variaveis.
// 4. Calcular a media.
// 5. Mostrar a media.

#include <stdio.h>

int main() {
  
  // 1. Criar 4 variaveis para armazenar os 4 numeros e 
  //    uma para armazenar a media.
  float num1, num2, num3, num4, media;

  // 2. Pedir para a pessoa digitar os 4 numeros.
  printf("=== Calculadora de media aritmetica (de 4 numeros)  ===\n");
  printf("Digite 4 numeros: ");

  // 3. Ler os 4 numeros e armazenar nas 4 variaveis.
  scanf("%f %f %f %f", &num1, &num2, &num3, &num4);
  
  // 4. Calcular a media.
  media = (num1 + num2 + num3 + num4)/4;
  
  // 5. Mostrar a media, com 3 casas decimais.
  printf("Parabens, veja sua media: %.3f\n", media);

  return(0);
}

#include <stdio.h>

/* int main() {

  float num, soma, media;
  
  printf("=== Calculadora de media aritmetica (de 4 numeros)  ===\n");
  printf("Digite 4 numeros: ");
  soma = 0;

  scanf("%f", &num);
  soma = soma + num;

  scanf("%f", &num);
  soma = soma + num;

  scanf("%f", &num);
  soma = soma + num;

  scanf("%f", &num);
  soma = soma + num;
  
  media = soma/4;
  
  printf("Parabens, veja sua media: %.3f\n", media);  

  return(0);
} */