#include <stdio.h>

int main(){
	int a = 12;
	int b = 2;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    printf("a : %d\nb : %d", a, b);
    return 0;
}

