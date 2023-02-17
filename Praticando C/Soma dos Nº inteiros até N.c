#include <stdio.h>

int main(void) {
  int soma, n;
  printf("Nº inteiro limitador: "); scanf("%d", &n);
  soma = (n * (n + 1)) / 2;
  printf("Soma = %d", soma);
  return 0;
}