#include <stdio.h>

int main(void) {
  char opcao;
  
  do{

    printf("\nM E N U\n");
    printf("\n");
    printf("c - Clientes\n");
    printf("f - Fornecedores\n");
    printf("e - Encomendas\n");
    printf("s - Sair\n");
    printf("\n");
    printf("Qual sua opção: "); scanf(" %c",&opcao);
    printf("\n");

    switch(opcao){
      case 'c':
        printf("Clientes.");
        break;
      case 'f':
        printf("Fornecedores.");
        break;
      case 'e':
        printf("Encomendas.");
        break;
      case 's':
        printf("Sair.\nAté logo!\n");
        break;
      default:
      printf("Opção INVÁLIDA!!!\n");
    }
    
  } while(opcao!='s' && opcao!='S');

  
  return 0;
}