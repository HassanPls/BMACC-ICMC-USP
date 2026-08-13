// Programa que le uma lista de 10 notas. Em seguida:
// 1. Mostra a lista na ordem lida.
// 2. Mostra a lista na ordem contraria.
// 3. Calcula e mostra a media aritmetica das notas.
// 4. Mostra quais notas estao abaixo desta media,
//    quais estao acima e quais sao iguais aa media.
// 5. Encontra e mostra a menos nota armazeda.
// 6. Encontra e mostra a menos nota armazeda em
//    posicoes pares do vetor de notas.

#include <stdio.h>

int main() {
  float notas[10],media,menor;
  int indice;

  // Preenche o vetor com as 10 notas, uma em cada posicao.
  for (indice = 0; indice < 10; indice++) {
    printf("Digite a %da nota: ", indice+1);
    scanf("%f", &notas[indice]);
  }

  // Mostra os valores das notas (na ordem original).
  printf("Notas na ordem em que foram lidas: ");
  
  for (indice = 0; indice < 9; indice++) {
    printf("%f ", notas[indice]);
  }
  
  // Aqui o indice vale 9, que eh a ultima posicao do vetor.
  // Mostra a ultima nota e pula linha.
  printf("%f\n", notas[indice]);

  // Mostra os valores das notas (de tras pra frente).
  printf("Notas na ordem inversa da que foram lidas: ");
  
  for (indice = 9; indice > 0; indice--) {
    printf("%f ", notas[indice]);
  }
  
  // Aqui o indice vale 0, que eh a primeira posicao do vetor.
  // Mostra a primeira nota e pula linha.
  printf("%f\n", notas[indice]);

  // Soma os numeros guardados no vetor.
  media = 0;
  for (indice = 0; indice < 10; indice++) {
    media = media + notas[indice];
  }

  // Calcula a media aritmetica dos numeros.
  media = media/10;

  // Mostra a media aritmetica dos numeros.
  printf("A media dos numeros eh %f\n", media);

  // Percorre todas as notas. Para cada uma verifica
  // e mostra qual esta na media, abaixo ou acima.
  for (indice = 0; indice < 10; indice++) {
    if (notas[indice] < media) {
      printf("A %da nota (%f) esta abaixo da media\n", indice+1, notas[indice]);
    }
    else {
      if (notas[indice] > media) {
	printf("A %da nota (%f) esta acima da media\n", indice+1, notas[indice]);
      }
      else {
	printf("A %da nota (%f) esta na media\n", indice+1, notas[indice]);
      }
    }
  }

  // Procura o menor numero do vetor. Comeca armazenando
  // na variavel "menor" o primeiro elemento do vetor.
  menor = notas[0];

  // Para cada elemento depois do primeiro, verifica se o que
  // esta armazenado em "menor" ainda eh menor do que ele. Caso
  // nao seja, atualiza o valor de "menor".
  for (indice = 1; indice < 10; indice++) {
    if (menor > notas[indice]) {
      menor = notas[indice];
    }
  }

  // Mostra o menor numero do vetor.
  printf("O menor numero eh %f\n", menor);

  // Procura o menor numero das casas com indices pares
  // do vetor. Comeca armazenando na variavel "menor"
  // o primeiro elemento do vetor, que esta na posicao 0.
  menor = notas[0];

  // Para cada elemento com indice par do vetor, depois do
  // primeiro, verifica se o que esta armazenado em "menor"
  // ainda eh menor do que ele. Caso nao seja, atualiza o
  // valor de "menor".
  for (indice = 2; indice < 10; indice = indice + 2) {
    if (menor > notas[indice]) {
      menor = notas[indice];
    }
  }

  // Mostra o menor numero de indice par.
  printf("O menor numero armazenado em indice par do vetor de numeros eh %f\n", menor);
  
  return(0);
}