// Corrida de letras.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// --------------------------------------------------------
// Funcao que espera t segundo.

void espera (double t) {
  clock_t agora,limite;

  agora  = clock();
  limite = agora + 0.2*CLOCKS_PER_SEC;

  while (limite > agora) {
    agora  = clock();
  }

  return;
}

// --------------------------------------------------------
// Funcao que mostra a pista.
// Recebe o numero de corredores (n_corr), o tamanho
// da pista (t_pis) e um vetor que tem, em cada elemento
// i, a posicao na pista da corredora i.
// Cada corredora eh representada por uma letra. A
// corredora 0 eh a letra A, a corredora 1 eh a letra
// B e assim por diante.

void mostra_pista(int n_corr, int t_pis, int p_corr[]) {
  int i,j;

  // Espera um pouco (0.2s) antes de limpar a tela.
  espera(0.2);
  
  // Limpa a tela. Para Windows, trocar "clear" por "cls".
  system("clear");
  
  // Mostra a pista com os corredores.
  for (i = 0; i < n_corr; i++) {
    printf("|");
    // Mostra o que vem antes do corredor.
    for (j = 0; j < p_corr[i]; j++) {
      printf("_");
    }
    // Mostra o corredor.
    printf("%c", 'A'+i);
    // Mostra o que vem depois do corredor.
    for (j = p_corr[i]+1; j < t_pis; j++) {
      printf("_");
    }
    printf("|\n");
  }

  return;
}

// --------------------------------------------------------
// Funcao que verifica se alguem ganhou.
// Recebe o numero de corredores (n_corr), o tamanho
// da pista (t_pis) e um vetor que tem, em cada elemento
// i, a posicao na pista da corredora i.
// Devolve 0 se ninguem chegou no final e 1 caso contrario.

int alguem_ganhou_interrogacao(int n_corr, int t_pis, int p_corr[]) {
  int i;
  
  for (i = 0; i < n_corr; i++) {
    if (p_corr[i] == t_pis-1) {
      return(1);
    }
  }

  return(0);
}

// --------------------------------------------------------
// Funcao principal.

int main() {
  int num_corredores, tam_pista,i,terminou;
  int pos_corredor[26];

  // Inicializa a semente para gerar numeros aleatorios.
  srand(time(NULL));
  
  // Le a quantidade de corredores e o tamanho da pista.
  do {
    printf("Digite o numero de corredores e o tamanho da pista: ");
    scanf("%d %d", &num_corredores, &tam_pista);
  } while((num_corredores <= 1) || (num_corredores > 26) || (tam_pista <= 1));

  // Coloca todos os corredores no inicio da pista.
  // A pista vai de 0 ate tam_pista-1.
  for (i = 0; i < num_corredores; i++) {
    pos_corredor[i] = 0;
  }

  // Mostra a pista.
  mostra_pista(num_corredores,tam_pista,pos_corredor);

  terminou = 0;

  // Enquanto ninguem chega no final da pista...
  while(terminou == 0) {
    
    // Faz uma rodada para ver se cada corredor anda ou nao.
    for (i = 0; i < num_corredores; i++) {
      pos_corredor[i] = pos_corredor[i] + (rand() % 2);
    }
    
    // Mostra a pista atualizada.
    mostra_pista(num_corredores,tam_pista,pos_corredor);
    
    // Analisa se alguem chegou no final da pista.
    terminou = alguem_ganhou_interrogacao(num_corredores,tam_pista,pos_corredor);
  }
  
  return(0);
}