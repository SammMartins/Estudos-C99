#include <stdio.h>
#define Char_Max 25

int main(void) {
  char NC[30][Char_Max+1];
  int x,y;
  for (y=0;y<30;y++)
  {
    gets(NC[y]); 
    if (NC[y]=='\0')
      break;
  }
  for (y=0;y<30;y++) 
  {
    if (NC[y]=='\0') 
      break;
    else
      printf("%s - ",NC[y]);
  }
  
  return 0;
}