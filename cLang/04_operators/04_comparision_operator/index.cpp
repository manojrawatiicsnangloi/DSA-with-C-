#include <stdio.h>

int main(){
	
	int age;
	printf("Enter age");
	scanf("%d", &age);
	if(age > 18){
		printf("Ready to vote");
	}	
	else{
		printf("Not ready to vote");
	}
	return 0;
}
