// Programa que le dois complexos x e y e faz as
// seguintes operacoes: soma x e y, multiplica
// x e y, calcula o modulo de x e de y, calcula
// o conjugado de x e de y.

#include <stdio.h>
#include <math.h>

typedef struct _complexo {
  double real,imag;
} complexo;

// -----------------------------------------
// Funcao que recebe dois numeros complexos
// a e b e devolve a soma desses numeros.

complexo soma_complexos(complexo a, complexo b) {
  complexo soma;

  soma.real = a.real + b.real;
  soma.imag = a.imag + b.imag;

  return(soma);
}

// -----------------------------------------
// Funcao que recebe dois numeros complexos
// a e b e devolve a multiplicacao desses
// numeros.

complexo multiplica_complexos(complexo a, complexo b) {
  complexo produto;

  produto.real = a.real * b.real - a.imag * b.imag;
  produto.imag = a.real * b.imag + a.imag * b.real;

  return(produto);
}

// -----------------------------------------
// Funcao que recebe um numero complexo a
// e devolve o modulo deste numero.

double mod_complexo(complexo a) {
  double modulo;

  modulo = sqrt(a.real * a.real + a.imag * a.imag);
  
  return(modulo);
}

// -----------------------------------------
// Funcao que recebe um numero complexo a
// e devolve seu conjugado.

complexo conjugado_complexo(complexo a) {
  complexo conjugado;

  conjugado.real = a.real;
  conjugado.imag = -a.imag;

  return(conjugado);
}

// -----------------------------------------
// Funcao que recebe um numero complexo a
// e o imprime.

void imprime_complexo(complexo a) {
  printf("%.2lf + (%.2lf)i", a.real, a.imag);

  return;
}

// -----------------------------------------
// Funcao principal.

int main() {
  complexo x,y,resultado;
  
  // Le os dois numeros complexos.
  printf("Digite a parte real e imaginaria de dois numeros complexos: ");
  scanf("%lf %lf %lf %lf", &(x.real), &(x.imag), &(y.real), &(y.imag));

  // Mostra os numeros lidos.
  printf("Os numeros lidos sao:\nx = ");
  imprime_complexo(x);
  printf(" e y = ");
  imprime_complexo(y);
  printf("\n");

  // Soma os numeros.
  resultado = soma_complexos(x,y);

  // Mostra a soma.
  printf("A soma eh : ");
  imprime_complexo(resultado);
  printf("\n");

  // Multiplica os numeros.
  resultado = multiplica_complexos(x,y);

  // Mostra o produto.
  printf("O produto eh: ");
  imprime_complexo(resultado);
  printf("\n");

  // Calcula o modulo de x.
  // Como o modulo eh um double, armazenamos
  // no campo "real" do "resultado".
  resultado.real = mod_complexo(x);

  // Mostra o modulo de x.
  printf("O modulo de x numero eh: %.2lf\n", resultado.real);

  // Calcula o modulo de y.
  resultado.real = mod_complexo(y);

  // Mostra o modulo de y.
  printf("O modulo de y numero eh: %.2lf\n", resultado.real);

  // Calcula o conjugado de x.
  resultado = conjugado_complexo(x);

  // Mostra o conjugado de x.
  printf("O conjugado de x eh: ");
  imprime_complexo(resultado);
  printf("\n");
  
  // Calcula o conjugado de y.
  resultado = conjugado_complexo(y);

  // Mostra o conjugado de y.
  printf("O conjugado de y eh: ");
  imprime_complexo(resultado);
  printf("\n");
  
  return(0);
}