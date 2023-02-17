#include <stdio.h>

int main(void) {
int n, num;

  n = 1;

  while(n<=5){
    num=1;
  while(num<=10){
    printf("%d * %2d = %2d\n", n, num, n*num);
    num = num +1;
    
} n = n + 1; printf("\n");

}
  
  return 0;
}