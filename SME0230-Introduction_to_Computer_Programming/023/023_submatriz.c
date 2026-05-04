#include <stdio.h>

int main()
{

    // variaveis de controle e de resultados
    int n, soma = 0, somaMaior, coordenada = 0, tamanhoMaior = 1, tamanho = 1;
    scanf("%d", &n);

    // verifica se o tamanho da matriz é válido
    if (n <= 0)
    {
        printf("Entrada invalida.");
        return 0;
    }

    // cria a matriz desse tamanho
    int matriz[n][n];

    // obtem os itens de cada matriz
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }

    // define o começo como o maior primeiramente
    somaMaior = matriz[0][0];
    for (int h = 0; h < n; h++)
    { // quantidade de tipos de submatrizes (1x1, 2x2, 3x3...)
        for (int i = 0; i < n - h; i++)
        { // quantidade de matrizes que existe dentro das submatrizes (1x1 -> 4, 2x2 -> 3...)
            // passa pela matriz, soma tudo
            for (int j = i; j < tamanho + i; j++)
            {
                for (int k = i; k < tamanho + i; k++)
                {
                    soma = soma + matriz[j][k];
                }
            }

            // verifica se essa soma é a maior que tem
            if (somaMaior < soma) {
                somaMaior = soma; // valor da soma
                coordenada = i; // local onde está essa submatriz
                tamanhoMaior = tamanho; // tamanho da submatriz
            }
            soma = 0; // reseta para a próxima verificação
        }
        tamanho++; // aumenta para o próximo tamanho de submatriz
    }

    printf("Soma: %d\n", somaMaior);  // mostra a maior soma
    for (int i = coordenada; i < coordenada + tamanhoMaior; i++)
    { // pega a coordenada e printa até o tamanho da submatriz
        for (int j = coordenada; j < coordenada + tamanhoMaior; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    /* matriz exemplo - 4x4
    1x1 -> 4
    2x2 -> 3
    3x3 -> 2
    4x4 -> 1 */

    return 0;
}