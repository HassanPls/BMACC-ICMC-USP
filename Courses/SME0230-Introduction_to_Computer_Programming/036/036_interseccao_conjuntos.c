// Programa que le dois conjuntos de inteiros
// e calcula a interseccao desses conjuntos.

#include <stdio.h>
#include <stdlib.h>

// -----------------------------------------
// Funcao que cria e le os elementos de
// um conjunto C. Devolve o tamanho de C.

int cria_e_le_conjunto(int **C) {
  int tamC, indice, elemento;
  
  // Le o tamanho do conjunto.
  printf("Digite o numero de elementos do conjunto: ");
  scanf("%d", &tamC);
  
  // Cria um vetor para armazenar os elementos do conjunto.
  *C = (int *) malloc(tamC * sizeof(int));

  // Verifica se conseguiu fazer a alocacao.
  if (*C == NULL) {
    printf("Erro na alocacao de memoria\n");
    return(-1);
  }

  // Le os elementos do conjunto.
  printf("Digite os elementos do conjunto: ");

  // Exercicio: mudar a leitura para NAO permitir
  // elementos repetidos no conjunto.
  for (indice = 0; indice < tamC; indice++) {
    scanf("%d", &elemento);
    (*C)[indice] = elemento;
  }

  // Devolve o tamanho do conjunto.
  return(tamC);
}

// -----------------------------------------
// Verifica se um elemento "e" pertence ao
// conjunto C, com tamC elementos.
// Se "e" pertence a C, devolve 1. Senao,
// devolve 0.

int pertence(int e, int *C, int tamC) {
  int indice;

  for (indice = 0; indice < tamC; indice++) {
    if (e == C[indice]) {
      return(1);
    }
  }

  return(0);
}

// -----------------------------------------
// Funcao principal.

int main() {
  int *A, *B, *I, tamA, tamB, tamI, indice;

  // Le o tamanho do conjunto A, cria o
  // vetor para armazenar os elementos de
  // A e le os elementos de A.
  tamA = cria_e_le_conjunto(&A);

  // Le o tamanho do conjunto B, cria o
  // vetor para armazenar os elementos de
  // B e le os elementos de B.
  tamB = cria_e_le_conjunto(&B);

  // Exercicio: verificar se tamA ou tamB deu -1.
  
  // Calcula o numero de elementos da interseccao dos conjuntos A e B.
  tamI = 0;
  for (indice = 0; indice < tamA; indice++) {
    tamI = tamI + pertence(A[indice], B, tamB);
  }

  // Cria o vetor para armazenar a interseccao de A e B.
  I = (int *) malloc(tamI * sizeof(int));

  if (I == NULL) {
    printf("Erro na alocacao de memoria.\n");
    return(-2);
  }
  
  // Calcula a interseccao dos conjuntos A e B.
  // Exercicio: transformar o calculo da interseccao
  // em uma funcao.
  tamI = 0;
  for (indice = 0; indice < tamA; indice++) {
    if (pertence(A[indice], B, tamB) == 1) {
      I[tamI] = A[indice];
      tamI++;
    }
  }

  // Mostra a interseccao I.
  // Exercicio: mostra o resultado da interseccao
  // em uma funcao.

  printf("A cap B = { ");
  for (indice = 0; indice < tamI; indice++) {
    printf("%d ", I[indice]);
  }
  printf("}\n");
  
  return(0);
}