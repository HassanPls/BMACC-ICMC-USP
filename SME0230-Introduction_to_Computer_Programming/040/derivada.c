#include <stdio.h>

float fx(float t, int d, float *graus)
{
    float result = 0;

    for (int i = 0; i < d + 1; i++)
    {
        float valor = *(graus + i);
        float t_elevado = 1;
        for (int j = 0; j < d - i; j++)
        {
            t_elevado = t_elevado * t;
        }

        result += valor * t_elevado;
    }

    return result;
}

float fxlinha(float t, int d, float *graus)
{
    float result = 0;

    for (int i = 0; i < d; i++)
    {
        float valor = *(graus + i) * (d - i);
        float t_elevado = 1;

        for (int j = 0; j < d - i - 1; j++)
        {
            t_elevado = t_elevado * t;
        }

        result += valor * t_elevado;
    }

    return result;
}

int main()
{
    float t;
    int d;

    scanf("%g %d", &t, &d);

    float graus[d + 1];

    for (int i = 0; i < d + 1; i++)
    {
        scanf("%g", &graus[i]);
    }

    if (graus[0] == 0)
    {
        printf("Entrada invalida.");
        return 0;
    }

    printf("f(x) = ");

    for (int i = 0; i < d + 1; i++)
    {
        if (graus[i] != 0)
        {
            printf("(%g)x^%d", graus[i], d - i);
        }
        if (i < d && graus[i + 1] != 0)
        {
            printf(" + ");
        }
    }

    printf("\nf'(x) = ");

    for (int i = 0; i < d + 1; i++)
    {
        if (d == 0) {
            printf("(0)");
        }
        if (graus[i] != 0 && (d - i - 1) >= 0)
        {
            printf("(%g)x^%d", graus[i] * (d - i), d - i - 1);
        }
        if (i < d - 1 && graus[i + 1] != 0)
        {
            printf(" + ");
        }
    }

    float fa = fx(t, d, &graus[0]);
    float falinha = fxlinha(t, d, &graus[0]);

    printf("\ny - (%g) = %g(x - (%g))", fa, falinha, t);

    return 0;
}