#include <stdio.h>

int main(){
	
	int n;
	printf("Enter Number");
	scanf("%d", &n);
	if(n % 2 == 0){
		printf("Even");
	}	
	else{
		printf("ODD");
	}
	return 0;
}
