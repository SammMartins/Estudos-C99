#include <stdio.h>

int main(void) 
{
  int n=0,num;
  int soma,prod; soma=0; prod=1;
  printf("Nº inteiro limitador: "); scanf("%d",&n);
  for (num=1;num<=n;num++) {
    soma+=num; prod=prod*num;
  } printf("\tSoma = %d\n\tProduto = %d",soma,prod);

  return 0;
}