#include <stdio.h>

int main(){
	int num;
	printf("Enter value num");
	scanf("%d", &num);
	int r = 1;
	while (num != 1){
		r *= num;
		num--;
	}
	printf("%d", r);
	return 0;
}
