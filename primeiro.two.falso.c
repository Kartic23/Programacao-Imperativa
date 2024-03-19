#include <stdio.h>

int main() 
{
  int n,     
  int i,     
  int soma;  

  printf("\nCalculo da soma dos n primeiros inteiros positivos\n");
  

  printf("\nDigite o valor de n: ");
  scanf("%d", &n);
  soma = 0;
  i = 1
  
  while (i <= n) 
  {
    soma = soma + i;
    i = i + 1;
  }
  
  printf("A soma dos %d primeiros inteiros positivos e´ %d\n", n, soma);
  
  return 0;
}
