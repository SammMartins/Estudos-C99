#include <stdio.h>

int main(void) {

  char Ncomp[50];
  int i;
  char c;
  gets(Ncomp);

  for (i=0,c=Ncomp[i];c!='\0';i++,c=Ncomp[i])
    ;
  printf("O nome '%s' tem '%d' caracteres.",Ncomp,i);
  return 0;
}