#include <stdio.h>
#include <stdlib.h> // Contém as funções rand(), srand() e a constante RAND_MAX
#include <time.h>   // Contém a função time() para gerar a semente temporal

int main() {
    // -------------------------------------------------------------------------
    // 1. CONFIGURAÇÃO DA SEMENTE (srand)
    // -------------------------------------------------------------------------
    // O computador é determinístico. Se não usarmos srand(), a função rand()
    // vai gerar sempre a mesma sequência de números toda vez que o programa rodar.
    // Usamos time(NULL) para pegar o tempo atual em segundos, garantindo uma
    // semente diferente a cada segundo que o programa é executado.
    srand(time(NULL));

    printf("=== GERADOR DE NÚMEROS PSEUDOALEATÓRIOS ===\n\n");

    // -------------------------------------------------------------------------
    // 2. NÚMERO INTEIRO EM UM INTERVALO ESPECÍFICO (Ex: Mega-Sena de 1 a 60)
    // -------------------------------------------------------------------------
    // rand() sozinho gera um número entre 0 e RAND_MAX.
    // Usamos o operador de resto da divisão (%) para limitar o intervalo.
    // rand() % 60 resulta em um número de 0 a 59.
    // Somamos +1 para deslocar o intervalo para 1 a 60.
    int numero_mega = (rand() % 60) + 1;
    printf("1. Inteiro no intervalo [1, 60] (Mega-Sena): %d\n", numero_mega);

    // -------------------------------------------------------------------------
    // 3. NÚMERO DECIMAL (PONTO FLUTUANTE) ENTRE 0 E 1
    // -------------------------------------------------------------------------
    // Para obter um número entre 0.0 e 1.0, dividimos o valor gerado por rand()
    // pelo valor máximo que ele pode atingir (RAND_MAX).
    // CRÍTICO: É obrigatório usar o (float) antes para fazer o "casting" (conversão).
    // Se fizermos divisão inteira (int / int), o resultado seria sempre 0.
    float valor_decimal = (float)rand() / (float)RAND_MAX;
    printf("2. Decimal aleatorio no intervalo [0.0, 1.0]: %f\n", valor_decimal);

    // -------------------------------------------------------------------------
    // EXTRA: ENTENDENDO O RAND_MAX
    // -------------------------------------------------------------------------
    // Apenas para fins de conhecimento, este é o valor máximo que o rand() 
    // do seu compilador consegue gerar nativamente:
    printf("\nNota: O valor maximo possivel de RAND_MAX neste sistema e: %d\n", RAND_MAX);

    return 0;
}