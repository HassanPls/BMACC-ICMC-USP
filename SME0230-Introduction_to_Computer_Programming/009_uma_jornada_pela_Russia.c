/* 1 Descrição
Um jovem leitor decidiu iniciar a leitura dos clássicos russos, iniciando por “Os Irmãos Karmázov”,
mas percebeu que eles podem ser bem longos. Por isso, ele pede que você desenvolva um pequeno
sistema para possibilitar o acompanhanhamento de suas métricas.
Escreva um programa em C que calcule quantos dias serão necessários que ele conclua a leitura
do livro e a média de quantas páginas e capítulos serão lidos por dia. Esses dados devem ser
gerados a partir do número total de páginas do livro, o número total de capítulos, o tempo médio
que o garoto leva para ler uma página e quantos minutos por dia ele pretende dedicar à leitura
2 Entrada
A primeira linha lê quatro números: número de páginas do livro (inteiro), capítulos do livro
(inteiro), tempo médio para ler uma página em minutos (real) e minutos diponíveis por dia (real),
respectivamente. */

#include <stdio.h>

int main() {
    //definição das variaveis
    // tem que ser float se não as contas perdem casas decimais
    float numPages, charpBook; // informações do livro (número de páginas e número de capítulos)
    float minutePerPage, minuteAvaliable; // informações sobre a leitura (tempo para ler uma página e tempo disponível em um dia)
    float timeToFinish, pagePerDay, charpPerDay; // variáveis de controle/resultado

    // obtenção das informações para o sistema
    scanf("%f %f %f %f", &numPages, &charpBook, &minutePerPage, &minuteAvaliable);

    // calculos e atribuições nas variaveis
    pagePerDay = (minuteAvaliable/minutePerPage);
    charpPerDay = pagePerDay/(numPages/charpBook);
    timeToFinish = numPages/pagePerDay;

    // apresentação dos resultados
    printf("Tempo gasto para terminar: %.2f dias\n", timeToFinish);
    printf("Paginas por dia: %.2f\n", pagePerDay);
    printf("Capitulos por dia: %.2f\n", charpPerDay);

    return (0);
}