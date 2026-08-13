// Programa que le os coeficientes a, b e c e
// calcula as raizes reais de a x^2 + b x + c = 0.

#include <stdio.h>
#include <math.h>

// -------------------------------------------------------------
// Recebe os coeficientes a, b e c de uma equacao de segundo
// grau e os enderecos r1 e r2 de duas variaveis que irao 
// armazenar as raizes calculadas.
// Devolve a quantidade de raizes reais calculadas e, nos
// enderecos r1 e r2, coloca os valores das raizes calculadas,
// quando alguma raiz real existir.

int raizes(double a, double b, double c, double *r1, double *r2) {
  double delta;
  
  // Calcula o delta.
  delta = b*b - 4*a*c;
  
  // Calcula as raizes reais.

  // Caso que nao tem raizes reais.
  if (delta < 0) {
    return(0);
  }

  // Caso que tem 2 raizes reais iguais.
  if (delta == 0) {
    *r1 = (-b + sqrt(delta))/2*a;
    *r2 = *r1;

    return(1);
  }

  // Caso que tem 2 raizes reais distintas.
  *r1 = (-b + sqrt(delta))/2*a;
  *r2 = (-b - sqrt(delta))/2*a;
  
  return(2);
}

// -------------------------------------------------------------
// Funcao principal.

int main() {
  double a,b,c,x1,x2;
  
  // Pede e le os coeficientes da equacao de segundo grau.
  do {
    printf("Digite os coeficientes a, b e c de a x^2 + b x + c = 0: ");
    scanf("%lf %lf %lf", &a, &b, &c);
  } while (a == 0);

  // Chama a funcao apara calcular as raizes.
  int qtde_raizes = raizes(a,b,c,&x1,&x2);

  // Mostra as raizes reais.
  if (qtde_raizes == 0) {
    printf("A equacao nao possui raizes reais\n");
  }
  else {
    if (qtde_raizes == 1) {
      printf("As raizes sao iguais: %lf\n", x1);
    }
    else {
      printf("As raizes sao: %lf e %lf\n", x1, x2);
    }
  }
  
  return(0);
}