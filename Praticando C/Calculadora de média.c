#include <stdio.h>
char aval(float a, float b, float c, float d)
{
  float nota_tot;
  nota_tot=(a+b+c+d)/4;
  if (nota_tot>=70) 
  {return 'A';} else return 'R';
};

int main() {
  float nota1,nota2,nota3,nota4;
  int resp=1;
  do {
    printf("Digite a primeira nota: "); scanf("%f",&nota1);
    printf("Digite a segunda nota: "); scanf("%f",&nota2);
    printf("Digite a terceira nota: "); scanf("%f",&nota3);
    printf("Digite a quarta nota: "); scanf("%f",&nota4);

    if (aval(nota1,nota2,nota3,nota4) == 'A') {
      printf("Caro aluno, você está aprovado\n");
    } 
    else printf("Caro aluno, você está reprovado\n");
      printf("\nInsira 0 caso queira finalizar o programa: "); scanf("%d",&resp);
  } while (resp);
  

  return 0;
}