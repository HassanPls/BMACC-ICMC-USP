/* Este programa cria duas variaveis inteiras,
   uma variavel real, atribui valores a elas e
   mostra algumas mensagens. */

#include <stdio.h>

int main() {
  // Declaracao das variaveis
  int var_int1; // Essa variavel armazena valores inteiros
  int var_int2;
  float var_real1, var_real2, troca;
  
  // Atribuicao de valores a elas
  var_int1 = 12; 
  var_int2 = 5; 
  var_real1 = 7.1; 
  
  // Mostra os valores das variaveis e algumas mensagens na tela
  printf("O valor inteiro eh %d! Que bom!\n", var_int1);
  printf("Temos duas variaveis inteiras, a primeira com valor %d e a segunda com valor %d\n", var_int1, var_int2);
  printf("A variavel real tem valor %f\n", var_real1);
  printf("Para pular linha em linguagem C use \\n e para mostrar inteiros use %%d\n");
  
  // Pede para digitar um numero real
  printf("Digite um numero real: ");
  
  // Le valor do teclado e armazena da variavel var_real1
  scanf("%f", &var_real1);
  
  // Mostra na tela o valor lido 
  printf("O valor lido foi %.2f\n", var_real1);	
  
  // Pede para digitar outro numero real
  printf("Digite outro numero real: ");
  
  // Le valor do teclado e armazena da variavel var_real2
  scanf("%f", &var_real2);
  
  // Mostra na tela o outro valor lido 
  printf("O valor lido foi %.2f\n", var_real2);	
  
  // Troca os valores das variaveis var_real1 e var_real2
  troca = var_real1;
  var_real1 = var_real2;
  var_real2 = troca;
  
  // Mostra os valores trocados
  printf("Os valores trocados sao: %.5f e %.5f\n", var_real1, var_real2);
  
  return(0);
}