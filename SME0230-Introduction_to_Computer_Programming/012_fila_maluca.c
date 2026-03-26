/* 1 Descrição
Um parque de diversões novo está tendo problemas de popularidade. Para resolver isso, tiveram
a ideia brilhante de “sortear” um brinde toda vez que alguém compra um ingresso. Você, sendo
muito esperto, percebeu um padrão na entrega desses brindes. Você sabe que a cada 5 pessoas:
 A primeira não ganha nada.
 A segunda ganha uma foto com o mascote.
 A terceira ganha uma lembrancinha
 A quarta ganha um cupom de desconto
 A quinta ganha um vale-vip, que permite você furar a fila em um brinquedo de sua escolha.
Para descobrir qual brinde você ganhará, você decidiu criar um programa em C que pega o
número de pessoas na fila que estão na sua frente e te diz qual será o brinde que você ganhará.
Porém, uma vez que o programa foi feito, você percebeu que não estava conseguindo a resposta
certa.
Corrija o código para dar a resposta correta e altere para que sua lógica use switch-case ao
ínves de if-else. */

#include <stdio.h>

int main() {

    // criação de variáveis 
    int peopleInFront, myPosition;

    // obtenção das informações
    scanf("%d", &peopleInFront);
    myPosition = peopleInFront % 5;

    // checagem do resultado
    switch (myPosition) {
        case 0:
            printf("Sinto muito! Voce nao ganhou nada...");
            break;
        case 1:
            printf("Parabens! Voce ganhou uma foto");
            break;
        case 2:
            printf("Parabens! Voce ganhou uma lembrancinha");
            break;
        case 3:
            printf("Parabens! Voce ganhou um cupom");
            break;
        case 4:
            printf("Parabens! Voce ganhou um vale-vip");
            break;
        default:
            break;
    }

    return 0;
}