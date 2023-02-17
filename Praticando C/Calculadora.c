#include <stdio.h>

int main(void) {
  int n1,n2,res=0;
  char operador;
  
  puts("Digite a operação no formato NÚMERO OPERADOR NÚMERO");
  scanf("%d %c %d", &n1, &operador, &n2);
  switch(operador) {
    case '+':
      res= n1 + n2;
      break;
    case '-':
      res= n1 - n2;
      break;
    case '/':
      res= n1 / n2;
      break;
    case 'x':
      res= n1 * n2;
      break;
    case '*':
      res= n1 * n2;
      break;
    case '%':
      res= n1 % n2;
      break;
    }
  printf("O resultado é %d", res);

  
  return 0;
}