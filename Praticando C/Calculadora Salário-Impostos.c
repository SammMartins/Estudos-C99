#include <stdio.h>

int main(void) {
  /*Escreva um programa que calcule o Salário Bruto, o Salário Líquido e o Imposto a pagar*/

  
  float sal,taxa;
  printf("Qual o salário? \nR$"); scanf("%f",&sal); 
  if (sal<1000) {
    taxa= .05;
  } 
  else {
    if (sal<5000){
      taxa= .11;
    } else taxa= .35;
  }
  printf("Salário: R$%.2f;\n O imposto total: R$%.2f;\n  Salário Líquido: R$%.2f.",sal,sal*taxa,sal-(sal*taxa));
    
  
 


  
return 0;}