/* Exerc ́ıcio 7 - O Jogo de Marienbad

1 Descri ̧c ̃ao
No enigm ́atico cl ́assico O Ano Passado em Marienbad (1961), somos transportados para os
corredores labir ́ınticos de um hotel de luxo europeu. E neste cen ́ario surreal que dois personagens  ́
(conhecidos apenas como X e M) se enfrentam repetidas vezes em uma varia ̧c ̃ao do jogo matem ́atico
de Nim, retirando em turnos palitos de f ́osforo dispostos sobre uma mesa.
Inspirado nesse duelo cinematogr ́afico, seu desafio  ́e criar um programa em C para arbitrar
uma partida dessa exata variante, controlando o fluxo do jogo e aplicando as regras em tempo de
execu ̧c ̃ao.
Regras do Jogo:
• A partida come ̧ca com uma quantidade inicial de palitos na mesa.
• Em seu turno, o jogador atual deve retirar 1, 2 ou 3 palitos.
• E estritamente proibido retirar mais palitos do que a quantidade restante na mesa.  ́
• Os turnos (Jogador 1 e Jogador 2) s ̃ao alternados at ́e que n ̃ao reste nenhum palito.
• A regra principal: o jogador que for for ̧cado a retirar o  ́ultimo palito perde o jogo.
O seu programa deve rejeitar jogadas inv ́alidas, exibindo um erro e repetindo o turno do jogador
atual at ́e que ele insira um valor correto. Ao final, o sistema deve declarar o vencedor e exibir qual
foi a maior quantidade de palitos retirada em uma  ́unica jogada v ́alida durante toda a partida.
2 Entrada
O primeiro inteiro positivo representa a quantidade inicial de palitos. Em seguida,  ́e fornecida
uma sequˆencia de n ́umeros inteiros representando a quantidade de palitos que cada jogador tenta
retirar em seu turno.
3 Sa ́ıda
• Se a quantidade inicial for inv ́alida, imprima exatamente: Erro: quantidade inicial
invalida
• Para cada tentativa de jogada inv ́alida, imprima exatamente: Erro: jogada invalida
• Ao fim da partida, anuncie o vencedor no formato: Vencedor: Jogador X (onde X  ́e 1 ou
2).
• Na linha seguinte, exiba a maior retirada validada: Maior retirada: Y */

#include <stdio.h>

int main() {

    // iniciando valores
    int palitos, jogada, i, mRetirada = 0;

    // recebendo quantidade de palitos
    scanf("%d", &palitos);

    // verifica validade dos palitos
    if (palitos <= 0) {
        printf("Erro: quantidade inicial invalida");
        return 0;
    }

    // perpassa pelas jogadas
    for (i = 1; palitos > 0; i++) {
        int firstTime = 1;
        //verifica a validade da jogada
        do {
            if (firstTime > 1) printf("Erro: jogada invalida\n");
            scanf("%d", &jogada);
            firstTime++;
        } while (jogada > palitos || jogada > 3 || jogada < 1);
        
        // retira os palitos
        palitos -= jogada;
        if (jogada > mRetirada) mRetirada = jogada;
    }
    
    // define o ganhador
    if (!(i % 2)) {
        printf("Vencedor: Jogador 2\n");
    } else {
        printf("Vencedor: Jogador 1\n");
    }

    // mostra a maior quantidade retirada
    printf("Maior retirada: %d\n", mRetirada);

    return 0;
}