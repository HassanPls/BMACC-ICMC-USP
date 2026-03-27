/* 1 Descrição
Em sistemas de processamento digital de sinais, um áudio analógico precisa ser convertido para
o formato digital para poder ser interpretado pelo computador. Esse processo envolve a frequência
de amostragem do sinal (como se tirássemos várias ’fotos’ do som a cada segundo, medida em
amostras por segundo) e a quantização (quantos bits são usados para armazenar cada uma dessas
’fotos’ ou amostras). O tamanho total do arquivo gerado dependerá, portanto, do número de bits
de cada amostra, da frequência com que elas são coletadas por segundo e da duração total do áudio.
Quanto maiores a frequência e a quantização, maior será a qualidade do áudio, mas também maior
será o arquivo.
Escreva um programa em C que leia a frequência de amostragem, a resolução em bits e a
duração do áudio em segundos, e calcule o tamanho total do áudio gerado em bytes.
2 Entrada
A primeira linha toma três inteiros: frequência, resolução em bits de cada registro e duração
do áudio em segundos, respectivamente. */

#include <stdio.h>

int main() {
    //definição das variaveis
    float bytes, bits;
    int frequency, resolution, timeInSeconds; // informações gerais do áudio analógico

    // obtenção das informações para o sistema
    scanf("%d %d %d", &frequency, &resolution, &timeInSeconds);

    // calculos e atribuições nas variaveis
    bits = frequency * resolution * timeInSeconds;
    bytes = bits/8;

    // apresentação do resultado
    printf("O audio tem %.2f bytes", bytes);

    return (0);
}