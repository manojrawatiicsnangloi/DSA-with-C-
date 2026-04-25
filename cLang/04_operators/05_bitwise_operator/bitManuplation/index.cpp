#include <stdio.h>

int main(){
	int n = 12;
	int i = 2;
	
//	get bit
    printf("%d\n", (n >> i) & 1);
// set bit
    printf("%d\n", (1 << i) | n);
// toggle bit
    printf("%d\n", (1 << i) ^ n);
// clear bit
    printf("%d\n", ~(1 << i) & n);

    return 0;
}

