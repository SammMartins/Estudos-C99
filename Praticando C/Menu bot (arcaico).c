#include <stdio.h>

int main(void) {
  printf("\tMENU PRINCIPAL\n");
  char c;
  do 
  {
    printf("\nEscolha uma opção: \n");
    printf("Clientes (C)\n");
    printf("Fornecedores (F)\n");
    printf("Encomendas (E)\n");
    printf("Sair (S)\n");
    printf("->\t"); scanf("%c",&c);
    fflush(stdin); /* Limpar o Buffer do teclado */
    switch(c) 
    {
      case 'c':
      case 'C': printf("Clientes.\n"); break;
      case 'f':
      case 'F': printf("Fornecedores.\n"); break;
      case 'e':
      case 'E': printf("Encomendas.\n"); break;
      case 's':
      case 'S': printf("\n"); /*Nada a ser feito*/
            break;
      default: printf("Opção inválida.\n");
    }
  } while (c!='s' && c!='S');
  printf("Programa finalizado."); 
return 0;
} 