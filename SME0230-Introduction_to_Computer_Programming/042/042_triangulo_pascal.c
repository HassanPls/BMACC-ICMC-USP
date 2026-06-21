// Programa que le um n e mostra as
// n primeiras linhas do Triangulo de
// Pascal.
//
// 1
// 1 1
// 1 2 1
// 1 3 3 1
// 1 4 6 4 1
// ...

#include <stdio.h>
#include <stdlib.h>

// -----------------------------------------
// Funcao que aloca um triangulo T, com k
// linhas. Devolve -1 se deu erro e 0 se
// deu certo.

int alocar(int ***T, int k) {
  int i, j;
  
  // Aloca o vetor de linhas.
  *T = (int **) malloc(k * sizeof(int *));

  if (*T == NULL) {
    printf("Deu errado\n");
    return(-1);
  }

  // Aloca cada linha do triangulo.
  for (i = 0; i < k; i++) {
    (*T)[i] = (int *) malloc((i+1) * sizeof(int));
    
    if ((*T)[i] == NULL) {
      printf("Deu errado quando tentou alocar a linha %d\n", i+1);
      
      // Desaloca as linhas anteriores.
      for (j = i-1; j >= 0; j--) {
	free((*T)[j]);
      }
      
      // Desaloca o vetor de linhas.
      free(*T);
      *T = NULL;
      
      return(0);
    }
  }

  return(0);
}

// -----------------------------------------
// Funcao que mostra o Triangulo de Pascal
// T, com k linhas.

void mostrar(int **T, int k) {
  int i, j;
  
  for (i = 0; i < k; i++) {
    for (j = 0; j <= i; j++) {
      printf("%5d ", T[i][j]);
    }
    printf("\n");
  }

  return;
}

// -----------------------------------------
// Funcao que preenche o Triangulo de Pascal
// T com k linhas. 

void preencher(int **T, int k) {
  int i, j;
  
  // Preenche os 1s na 1a coluna e na diagonal.
  for (i = 0; i < k; i++) {
    T[i][0] = 1;
    T[i][i] = 1;
  }

  // Preenche o resto.
  for (i = 2; i < k; i++) {
    for (j = 1; j < i; j++) {
      T[i][j] = T[i-1][j] + T[i-1][j-1];
    }
  }

  return;
}

// -----------------------------------------
// Funcao principal.

int main() {
  int i, flag, n, **Triangulo;

  // Le a quantidade de linhas.
  printf("Digite quantas linhas do Triangulo de Pascal voce quer ver: ");
  scanf("%d", &n);

  // Aloca o triangulo.
  flag = alocar(&Triangulo,n);

  if (flag == -1) {
    return(-1);
  }
  
  // Preenche o Triangulo de Pascal.
  preencher(Triangulo,n);

  // Mostra o Triangulo de Pascal.
  mostrar(Triangulo,n);
  
  // Desaloca o Triangulo.
  for (i = n-1; i >= 0; i--) {
    free(Triangulo[i]);
  }
  free(Triangulo);
  Triangulo = NULL;
  
  return(0);
}