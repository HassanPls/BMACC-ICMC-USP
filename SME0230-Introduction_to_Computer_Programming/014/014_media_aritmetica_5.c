// Programa que calcula a media 
// aritmetica de n numeros, com n
// definido pelo(a) usuario(a). Usa
// "for" para fazer a repeticao. 

#include <stdio.h>

int main() {
  float num, soma, media;
  int repeticao, q_rep;

  // Comeca o soma em 0.
  soma = 0;

  // Pergunta quantos numeros a pessoa quer digitar
  printf("Voce quer calcular a media aritmetica de quantos numeros? ");

  // Le quantos numeros a pessoa quer
  scanf("%d", &q_rep);
  
  // Repete q_rep vezes. Ou seja,
  // comeca o contador de repeticoes em 0
  // (comando antes do primeiro ";" do "for"),
  // aumenta o contador de repeticoes de 1 em 1
  // (comando depois do segundo ";" do "for")
  // e repete enquanto esse contador eh
  // menor que q_rep (condicao do "for", entre
  // os dois ";").
  for (repeticao = 0; repeticao < q_rep; repeticao++) {
    
    // Pede para digitar um numero.
    printf("Digite %do numero: ", repeticao+1);

    // Le o numero digitado.
    scanf("%f", &num);

    // Soma o numero na soma parcial.
    soma = soma + num;

    // Atualiza o numero de repeticoes,
    // executando o comando final do "for",
    // depois do segundo ";".
  }

  // Calcula a media.
  media = soma / q_rep;

  // Mostra a media.
  printf("A media aritmetica dos numeros digitados eh %f\n", media);
  
  return(0);
}