// Programa que le 2 matrizes n x m e
// calcula a soma dessas matrizes.

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
// Funcao que mostra na tela uma matriz Mat,
// com lin linhas e col colunas.

void imprime_matriz(double **Mat, int lin, int col) {
  int i,j;

  for (i = 0; i < lin; i++) {
    for (j = 0; j < col; j++) {
      printf("%.2lf ", Mat[i][j]);
    }
    printf("\n");
  }
  printf("\n");
 
  return;
}

// -----------------------------------------
// Funcao principal.

int main() {
  int linha, coluna;
  double **Mat1, **Mat2, **MatSoma;
    
  // Le o numero de linhas e colunas.
  printf("Digite o numero de linhas e colunas das matrizes: ");
  scanf("%d %d", &linha, &coluna);
  
  // Aloca a primeira matriz.
  Mat1 = aloca_matriz(linha,coluna);

  // Verifica se deu erro na alocacao da primeira matriz.
  if (Mat1 == NULL) {
    return(-1);
  }
  
  // Aloca a segunda matriz.
  Mat2 = aloca_matriz(linha,coluna);

  // Verifica se deu erro na alocacao da segunda matriz.
  if (Mat2 == NULL) {
    return(-1);
  }

  // Le os elementos da primeira matriz.
  preenche_matriz(Mat1,linha,coluna);

  // Mostra os elementos da primeira matriz.
  imprime_matriz(Mat1,linha,coluna);

  // Le os elementos da segunda matriz.
  preenche_matriz(Mat2,linha,coluna);

  // Mostra os elementos da segunda matriz.
  imprime_matriz(Mat2,linha,coluna);

  // Calcula a soma das matrizes.
  MatSoma = soma_matrizes(Mat1,Mat2,linha,coluna);

  // Verifica se deu erro na alocacao da matriz.
  if (MatSoma == NULL) {
    return(-1);
  }

  // Mostra a matriz resultado na tela.
  printf("(Somando...)\n");
  imprime_matriz(MatSoma,linha,coluna);
  
  return(0);
}