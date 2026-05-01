// Online C compiler to run C program online
#include <stdio.h>

int c(int n){
    if (n == 0) return 0;
    return 1 + c(n / 10);
}



int main() {
    printf("%d", c(123));
    return 0;
}