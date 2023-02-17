//Conversor de temperatura

#include <stdio.h>

int main(void) {
  
float graus_c, graus_f;

  puts("Introduza a temperatura em Graus Fahrenheit:"); scanf("%f", &graus_f);
  graus_c=(graus_f-32)*5/9; printf("\nA temperatura %ffº é %f em graus Celsios.",graus_f,graus_c);
  
  return 0;
}