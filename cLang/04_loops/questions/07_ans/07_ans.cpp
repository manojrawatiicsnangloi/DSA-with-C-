#include <stdio.h>

int main(){
	int num;
	printf("Enter value num");
	scanf("%d", &num);
	int count = 0;
	while (num != 0){
        count++;
        num /= 10;
	}
    printf("%d", count);
	return 0;
}
