#include <stdio.h>

int main(void) {
  int i,j=1;

  for(j=1;j<=5;j++){
  
  for(i=1;i<=10;i++){
    printf("%d * %2d = %2d\n", j, i, j*i);  
} printf("\n");
}
  return 0;
}