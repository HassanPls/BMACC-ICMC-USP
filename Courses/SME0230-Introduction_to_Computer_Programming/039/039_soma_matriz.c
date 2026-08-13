// Programa que le 2 matrizes n x m e
// calcula a soma dessas matrizes.
// INCOMPLETO.

#include <stdio.h>
#include <stdlib.h>

// -----------------------------------------
// Funcao que aloca uma matriz lin x col.
// Recebe o numero de linhas lin, o numero
// de colunas col e devolve a matriz.

double **aloca_matriz(int lin, int col) {
  int i;
  double **matriz;

  matriz = (double **) malloc(lin * sizeof(double *));

  if (matriz == NULL) {
    printf("Erro na alocacao de memoria\n");
    return(NULL);
  }

  for (i = 0; i < lin; i++) {
    matriz[i] = (double *) malloc(col * sizeof(double));

    if (matriz[i] == NULL) {
      printf("Erro na alocacao de memoria\n");
      return(NULL);
    }
  }

  return(matriz);
}

// -----------------------------------------
// Funcao que preenche os elementos de uma
// matriz Mat, com lin linhas e col colunas.

void preenche_matriz(double **Mat, int lin, int col) {
  int i,j;
  
  printf("Digite os elementos da matriz:\n");
  for (i = 0; i < lin; i++) {
    printf("Digite os %d elementos da linha %d da matriz:\n", col, i+1);
    for (j = 0; j < col; j++) {
      scanf("%lf", &(Mat[i][j]));
    }
  }

  return;
}

// -----------------------------------------
// Funcao que soma as matrizes M1 e M2, cada
// uma com lin linhas e col colunas.

double **soma_matrizes(double **M1, double **M2, int lin, int col) {
  int i,j;
  double **Soma;

  // Aloca a matriz que vai armazenar a soma.
  Soma = aloca_matriz(lin,col);

  // Verifica se a alocacao funcionou.
  if (Soma == NULL) {
    return(NULL);
  }

  // Calcula a soma.
  for (i = 0; i < lin; i++) {
    for (j = 0; j < col; j++) {
      Soma[i][j] = M1[i][j] + M2[i][j];
    }
  }

  return(Soma);
}

// -----------------------------------------
// Funcao principal.

int main() {
  int linha, coluna;
  double **Mat1, **Mat2, **MatSoma;
    
  // Le o numero de linhas e colunas.
  printf("Digite o numero de linhas e colunas das matrizes: ");
  scanf("%d %d", &linha, &coluna);
  
  // Aloca as matrizes.
  Mat1 = aloca_matriz(linha,coluna);
  Mat2 = aloca_matriz(linha,coluna);

  // Verifica se deu erro na alocacao das matrizes.
  if ((Mat1 == NULL) || (Mat2 == NULL)) {
    return(-1);
  }

  // Le os elementos das matrizes.
  preenche_matriz(Mat1,linha,coluna);
  preenche_matriz(Mat2,linha,coluna);

  // Calcula a soma das matrizes.
  MatSoma = soma_matrizes(Mat1,Mat2,linha,coluna);

  // FALTA FAZER UMA FUNCAO PARA MOSTRAR UMA MATRIZ
  // E CHAMA-LA PARA MOSTRAR O RESULTADO DA SOMA.

  // FALTA TESTAR TODO O CODIGO.
  
  return(0);
}