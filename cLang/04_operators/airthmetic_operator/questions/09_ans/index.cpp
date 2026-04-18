#include <stdio.h>

int main(){
	int num;
	printf("Enter value num");
	scanf("%d", &num);
	
    int per;
	printf("Enter value per");
	scanf("%d", &per);
	
    scanf("%d", num * per / 100);
	return 0;
}
