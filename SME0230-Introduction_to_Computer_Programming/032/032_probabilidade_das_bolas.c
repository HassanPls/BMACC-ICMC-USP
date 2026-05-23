#include <stdlib.h>
#include <stdio.h>

float ProbabilidadeDaCor(int totalBolas, int qntBolasEsperadas) // função para calcular a probabilidade da cor sair
{
    return ((float)qntBolasEsperadas / totalBolas) * 100;
}

int modulo(int num) // função para calcular o módulo do número
{
    if (num < 0)
    {
        return num * -1;
    }
    else
    {
        return num;
    }
}

int main()
{

    srand(42); // definir seed da aleatoriedade
    int qntCores, indiceCorEsperada, totalSorteios, totalBolas = 0; // variaveis obtidas por inserção
    float margemErro;


    // obtenção das variáveis
    scanf("%d", &qntCores);

    int cores[qntCores];
    for (int i = 0; i < qntCores; i++)
    {
        scanf("%d", &cores[i]);
    }

    scanf("%d", &indiceCorEsperada);
    scanf("%d %f", &totalSorteios, &margemErro);

    // definindo o total de bolas
    for (int i = 0; i < qntCores; i++)
    {
        totalBolas += cores[i];
    }

    // chance de obter uma bola
    float porcentagem = ProbabilidadeDaCor(totalBolas, cores[indiceCorEsperada]);

    // mostrar a porcentagem
    printf("%.2f%%\n", porcentagem);

    // quantidades de bolas que deveriam ser sorteadas
    int valorEsperado = totalSorteios * (porcentagem / 100);
    printf("Valor esperado: %d\n", valorEsperado);

    // simulação de bolas sorteadas
    int valorSimulado = 0;
    int bolasRestantes = totalBolas;
    for (int i = 0; i < totalSorteios; i++)
    {
        int bolaSorteada = rand() % bolasRestantes; // indice da bola que foi sorteada

        int bolasContadas = 0;
        int corSorteada = -1;

        // verifica a cor da bola sorteada
        for (int j = 0; j < qntCores; j++)
        {
            bolasContadas += cores[j];
            if (bolaSorteada < bolasContadas)
            {
                corSorteada = j;
                break;
            }
        }

        // se for igual ao indice da cor esperada, então soma no valor simulado
        if (corSorteada == indiceCorEsperada)
            valorSimulado++;

        // retira as bolas do sorteio
        cores[corSorteada]--;
        bolasRestantes--;
    }
    // print da simulação
    printf("Valor simulado: %d\n", valorSimulado);

    // verifica se o valor simulado está dentro da margem de erro
    if (modulo(valorEsperado - valorSimulado) < (totalBolas * margemErro))
    {
        printf("Simulacao dentro da margem de erro");
    }
    else
    {
        printf("Simulacao fora da margem de erro");
    }

    return 0;
}