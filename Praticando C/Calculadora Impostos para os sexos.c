#include <stdio.h>

int main(void) {
  float sal, taxa=0.0;
  char sexo;
  printf("Qual o sexo? (F para feminino, M para masculino) "); sexo = getchar();
  printf("Qual o salário?\nR$"); scanf("%f",&sal);
  
  switch(sexo) {
    case 'm':
    case 'M':
      taxa+=0.05 /*Se for homem é adicionado 5% de taxa*/
    case 'f':
    case 'F':
      taxa+=0.10; /*Todos pagarão 10% de taxa (homens tem uma taxa a mais de 5%)*/
  } printf("O imposto total a pagar é: R$%.2f",sal*taxa);
  
  return 0;
}