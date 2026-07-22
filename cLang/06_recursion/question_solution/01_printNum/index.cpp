#include <stdio.h>

void pN(int n){
    if (n == 10){
        return;
    }
    
    printf("%d\n", n);
    pN(n + 1);
    
}

int main()
{
    pN(1);
    return 0;
}