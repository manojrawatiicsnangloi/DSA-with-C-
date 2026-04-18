#include <stdio.h>

int main(){
	int num;
	printf("Enter value num");
	scanf("%d", &num);
	int sm = 0;
	while (num != 0){
        sm += num % 10;
        num /= 10;
	}
    printf("%d", sm);
	return 0;
}
