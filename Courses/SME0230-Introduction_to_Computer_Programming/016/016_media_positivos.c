// Programa que le numeros positivos
// e calcula a media aritmetica desses
// numeros. Para de ler os numeros 
// quando le um numero negativo.

// Roteiro:
// 1. Criar uma variavel para guardar
//    a soma dos numeros lidos, uma
//    para a media, uma para a quanti-
//    dade de positivos, uma para o
//    numero lido.
// 2. Pedir para digitar os numeros.
// 3. Ler os numeros e somar, enquanto
//    o numero lido for positivo.
// 3.1. Incrementar a quantidade de
//      numeros lidos cada vez que le
//      um novo numero.
// 4. Calcular a media aritmetica.
// 5. Mostrar a media calculada.

#include <stdio.h>

int main() {
  int quantidade;
  float numero, soma, media;

  // Valor inicial das variaveis
  soma = 0;
  quantidade = 0;
  
  // Pede para a pessoa digitar um numero
  printf("Digite numeros positivos para calcular a media.\nDigite um numero negativo para indicar que ja digitou todos os numeros que queria.\n");

  // Le o primeiro numero
  scanf("%f", &numero);

  // Enquanto o numero lido for >= 0...
  while(numero >= 0) {
    // Soma o numero lido com os anteriores
    soma = soma + numero;
    
    // Aumenta em 1 a quantidade de numeros
    // somados
    quantidade = quantidade + 1;

    // Le o proximo numero
    scanf("%f", &numero);
  }

  /* -----------------------------------------------
     Uma forma de usar o "for" no lugar do "while" eh:
     
  for (quantidade = 0; numero >= 0; quantidade++) {
    // Soma o numero lido com os anteriores
    soma = soma + numero;
    
    // Le o proximo numero
    scanf("%f", &numero);
  }

  Note que, neste caso, nao precisaria colocar um
  valor inicial para a variavel quantidade la no
  inicio, ja que ela tem o valor inicial definido
  no "for".
  ----------------------------------------------- */

  // Se houve pelo menos 1 numero positivo digitado...
  if (quantidade != 0) {

    // Calcula a media aritmetica
    media = soma / quantidade;

    // Mostra a media calculada
    printf("A media eh %.3f\n", media);
  }
  
  return(0);
}