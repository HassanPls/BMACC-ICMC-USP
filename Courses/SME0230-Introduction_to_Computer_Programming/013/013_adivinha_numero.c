// Programa que define um numero,
// pede para a pessoa chutar o numero
// e diz se acertou, errou para cima
// ou errou para baixo. Repete enquanto
// a pessoa nao acertar.

// Roteiro:
// 1. Criar 4 variaveis, uma para o
//    numero escolhido, uma para o chute,
//    uma para a quantidade maxima de
//    tentativas e uma para contar as
//    tentativas feitas.
// 2. Escolher o numero e armazenar
//    na variavel.
// 3. Definir a quantidade maxima de
//    tentativas permitidas e quantas
//    tentativas ja foram feitas.
// 4. Repetir enquanto nao acertar e
//    ainda tiver tentativas sobrando:
// 4.1. Pedir para a pessoa chutar um
//      numero.
// 4.2. Ler e armazenar o numero digitado.
// 4.3. Comparar o numero digitado com o
//      numero escolhido.
// 4.4. Mostrar a mensagem de acordo com
//      a comparacao.
// 4.5. Atualizar a quantidade de tentativas.

#include <stdio.h>

int main() {
  // 1. Criar 4 variaveis, uma para o
  //    numero escolhido, uma para o chute,
  //    uma para a quantidade maxima de
  //    tentativas e uma para contar as
  //    tentativas feitas.
  int numero, chute, tentativas, max_tentativas;
  
  // 2. Escolher o numero e armazenar
  //    na variavel.
  numero = 257;

  // 3. Definir a quantidade maxima de
  //    tentativas permitidas e quantas
  //    tentativas ja foram feitas.
  max_tentativas = 2;
  tentativas = 0;
  
  // 4.1. Pedir para a pessoa chutar um
  //      numero.
  printf("Faca um chute para adivinhar o numero inteiro escolhido: ");
  
  // 4.2. Ler e armazenar o numero digitado.
  scanf("%d", &chute);
  
  // 4. Repetir enquanto nao acertar e
  //    ainda tiver tentativas sobrando:
  while ((chute != numero) && (tentativas < max_tentativas)) {

    // Observacao: note que, como a condicao do "while"
    // usa o chute, precisamos le-lo antes do "while".
    // Entao, ao chegar neste ponto, ja lemos um valor
    // do chute e sabemos que ele nao eh o mesmo de
    // numero. Por isso, ja podemos verificar se ele
    // eh maior ou menor que o numero, para mostrar a
    // mensagem adequada ao(a) usuario(a).

    // 4.3. Comparar o numero digitado com o
    //      numero escolhido.
    // 4.4. Mostrar a mensagem de acordo com
    //      a comparacao.    
    if (chute > numero) {
      printf("Voce chutou mais alto do que deveria\n");
    }
    else {
      printf("Voce chutou mais baixo do que deveria\n");
    }

    // 4.5. Atualizar a quantidade de tentativas.
    tentativas = tentativas + 1;

    // Soh precisamos ler novamente o chute caso o
    // numero de tentativas atualizado ainda nao
    // tenha atingido o maximo.
    if (tentativas < max_tentativas) {
      
      // 4.1. Pedir para a pessoa chutar um
      //      numero.
      printf("Tente novamente (falta(m) %d tentativa(s)): ", max_tentativas-tentativas);
      
      // 4.2. Ler e armazenar o numero digitado.      
      scanf("%d", &chute);
    }
  }

  // Quando termina o "while", temos 2 opcoes:
  // ou ele parou porque o chute foi correto ou porque
  // o numero maximo de tentivas foi atingido.
  // Entao, verificamos qual a opcao que aconteceu
  // para avisar para o(a) usuario(a).
  if (chute == numero) {
    printf("Parabens! Voce acertou!\n");
  }
  else{
    printf("Game over! Suas tentativas acabaram!\n");
  }
  
  return(0);
}