#include <stdio.h>

int empate(int n, int *lastClassificado, int *numClassificados, int atletas[n][3])
{

    for (int i = *lastClassificado; i < n; i++)
    {
        int t1 = (atletas[i][0] * 1000) + atletas[i][1];
        int t2 = (atletas[i - 1][0] * 1000) + atletas[i - 1][1];
        if (t1 == t2 && atletas[i][2] == atletas[i - 1][2])
        {
            *lastClassificado = *lastClassificado + 1;
            *numClassificados = *numClassificados + 1;
        }
        else
        {
            break;
        }
    }

    return 0;
}

int classificador(int n, int v, int atletas[n][3], int *numClassificados, int *lastClassificado)
{

    for (int i = 0; i < n; i++)
    {

        if (*numClassificados >= v)
        {
            empate(n, lastClassificado, numClassificados, atletas);
            break;
        }

        int t = (atletas[i][0] * 1000) + atletas[i][1];
        if (atletas[i][2] >= 3)
        {
            continue;
        }
        else if (t >= 12100)
        {
            continue;
        }
        else
        {
            *numClassificados = *numClassificados + 1;
            *lastClassificado = i + 1;
        }
    }

    return 0;
}

int main()
{

    int v, n;

    int numClassificados = 0, lastClassificado = 0;

    scanf("%d %d", &v, &n);
    int atletas[n][3];

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &atletas[i][0], &atletas[i][1], &atletas[i][2]);
    }

    classificador(n, v, atletas, &numClassificados, &lastClassificado);

    if (numClassificados <= 0)
    {
        printf("Nenhum atleta foi classificado.");
    }
    else
    {
        printf("%d atletas foram classificados.\n", numClassificados);
        printf("O ultimo classificado foi o atleta numero %d.\n", lastClassificado);
    }

    return 0;
}