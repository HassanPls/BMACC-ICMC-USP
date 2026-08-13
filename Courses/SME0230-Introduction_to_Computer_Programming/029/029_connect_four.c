#include <stdio.h>

int checkGame(char tabuleiro[6][7])
{ // Função para verificar o jogo 
    // Verificação se o jogo está cheio
    int cheio = 0;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (tabuleiro[i][j] == 0)
                cheio++;
        }
    }
    if (cheio == 0)
        return 3;

    // Verificação Horizontal
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 4; j++)
        { // j vai até 3 pois verifica j, j+1, j+2, j+3
            if (tabuleiro[i][j] != 0 &&
                tabuleiro[i][j] == tabuleiro[i][j + 1] &&
                tabuleiro[i][j] == tabuleiro[i][j + 2] &&
                tabuleiro[i][j] == tabuleiro[i][j + 3])
            {
                return 0;
            }
        }
    }

    // Verificação Vertical
    for (int i = 0; i < 3; i++)
    { // i vai até 2 pois verifica i, i+1, i+2, i+3
        for (int j = 0; j < 7; j++)
        {
            if (tabuleiro[i][j] != 0 &&
                tabuleiro[i][j] == tabuleiro[i + 1][j] &&
                tabuleiro[i][j] == tabuleiro[i + 2][j] &&
                tabuleiro[i][j] == tabuleiro[i + 3][j])
            {
                return 0;
            }
        }
    }

    // Verificação Diagonal (Descendente: \)
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (tabuleiro[i][j] != 0 &&
                tabuleiro[i][j] == tabuleiro[i + 1][j + 1] &&
                tabuleiro[i][j] == tabuleiro[i + 2][j + 2] &&
                tabuleiro[i][j] == tabuleiro[i + 3][j + 3])
            {
                return 0;
            }
        }
    }

    // Verificação Diagonal (Ascendente: /)
    for (int i = 3; i < 6; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (tabuleiro[i][j] != 0 &&
                tabuleiro[i][j] == tabuleiro[i - 1][j + 1] &&
                tabuleiro[i][j] == tabuleiro[i - 2][j + 2] &&
                tabuleiro[i][j] == tabuleiro[i - 3][j + 3])
            {
                return 0;
            }
        }
    }

    return 1; // Jogo continua
}

int main()
{

    // Criação das estruturas e variáveis
    struct Jogador
    {
        char nome[50];
        char peca;
    };

    struct Jogador p1;
    struct Jogador p2;

    int whoWon = 0;

    char tabuleiro[6][7];

    // Preenchendo o tabuleiro
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            tabuleiro[i][j] = 0;
        }
    }

    // Obtendo os nomes e as peças
    scanf("%s", p1.nome);
    scanf(" %c", &p1.peca);

    scanf("%s", p2.nome);
    scanf(" %c", &p2.peca);

    // Se a peça for igual a 0 dá errado (já é usado no tabuleiro)
    if (p1.peca == 0 || p2.peca == 0)
    {
        printf("Entrada invalida.");
        return 0;
    }

    do
    { // Jogo se repete
        // Criação de variaveis
        int control;
        int jogada1, jogada2;
        scanf("%d %d", &jogada1, &jogada2);

        // Se não for a quantidade de colunas, dá errado
        if (jogada1 > 7 || jogada1 < 1 || jogada2 > 7 || jogada2 < 1)
        {
            printf("Entrada invalida.");
            return 0;
        }

        // Faz a jogada do jogador 1
        control = 0;
        for (int i = 5; i >= 0; i--)
        {
            if (tabuleiro[i][jogada1 - 1] == 0)
            {
                tabuleiro[i][jogada1 - 1] = p1.peca;
                break;
            }
            control++;
        }
        if (control >= 6)
        { // Verifica se jogou em uma coluna cheia
            printf("Entrada invalida.");
            return 0;
        }

        if (checkGame(tabuleiro) == 0)
        { // Verifica se ganhou
            whoWon = 1;
            break;
        }

        // Faz a jogada do jogador 2
        control = 0;
        for (int i = 5; i >= 0; i--)
        {
            if (tabuleiro[i][jogada2 - 1] == 0)
            {
                tabuleiro[i][jogada2 - 1] = p2.peca;
                break;
            }
            control++;
        }
        if (control >= 6)
        { // Verifica se jogou em uma coluna cheia
            printf("Entrada invalida.");
            return 0;
        }

        if (checkGame(tabuleiro) == 0)
        { // Verifica se ganhou
            whoWon = 2;
            break;
        }

        if (checkGame(tabuleiro) == 3)
        { // Verifica se o jogo encheu
            whoWon = 3;
            break;
        }

    } while (whoWon == 0); // Se for diferente de 0 o jogo acaba

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (tabuleiro[i][j] == 0)
                printf("0 ");
            else
                printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    } // mostra o jogo final

    // Verificação do status do jogo
    if (whoWon == 1)
        printf("%s ganhou!", p1.nome);
    else if (whoWon == 2)
        printf("%s ganhou!", p2.nome);
    else if (whoWon == 3)
        printf("Empate!");

    
    return 0;
}