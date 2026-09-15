#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GRAU 500000
#define NUM_TERMOS 50000
#define NUM_ESCALAS 20000

static int aleatorio(int min, int max)
{
    return min + rand() % (max - min + 1);
}

static void gerar_graus(int *graus)
{
    for (int i = 0; i <= MAX_GRAU; i++) {
        graus[i] = i;
    }

    for (int i = MAX_GRAU; i > 0; i--) {
        int j = rand() % (i + 1);

        int temp = graus[i];
        graus[i] = graus[j];
        graus[j] = temp;
    }
}

static void gerar_def(const char *nome, int *graus)
{
    printf("DEF %s %d\n", nome, NUM_TERMOS);

    for (int i = 0; i < NUM_TERMOS; i++) {
        int coef = aleatorio(-1000, 1000);

        printf("%d %d\n", coef, graus[i]);
    }
}

int main(void)
{
    srand((unsigned) time(NULL));

    int *graus = malloc((MAX_GRAU + 1) * sizeof(int));

    if (graus == NULL) 
        return 1;
    
    gerar_graus(graus);
    gerar_def("A", graus);

    for (int i = 0; i < NUM_ESCALAS; i++) {
        int c = (rand() % 2 == 0) ? -1 : 1;

        printf("ESCALA A %d\n", c);
    }

    printf("IMPRIME A\n");
    printf("GRAU A\n");

    gerar_graus(graus);
    gerar_def("B", graus);
    printf("SOMA A B R\n");
    printf("FIM\n");

    free(graus);

    return 0;
}