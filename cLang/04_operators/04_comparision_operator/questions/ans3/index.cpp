#include <stdio.h>

int main(){
	
	int n;
	printf("Enter Number");
	scanf("%d", &n);
	if(n % 4 == 0){
		printf("Leap Year");
	}	
	else{
		printf("Not Leap Year");
	}
	return 0;
}
