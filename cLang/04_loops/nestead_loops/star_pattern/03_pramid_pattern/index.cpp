// Online C compiler to run C program online
#include <stdio.h>

int main() {
int num = 5;
  int i = 1;
  while (i <= num){
      int k = 1;
      while (k <= num - i){
          printf("   ");
          k++;
          
      }
      
      int j = 1;
      
      while (j <= 2 * i - 1){
          printf(" * ");
          j++;
      }
      printf("\n");
      i++;
  }

    return 0;
}
