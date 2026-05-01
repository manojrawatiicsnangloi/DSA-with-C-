// Online C compiler to run C program online
#include <stdio.h>


int s(int n){
    if (n == 0) return 0;
    return n % 10 + s(n / 10);
}


int main() {
    printf("%d", s(123));
    return 0;
}