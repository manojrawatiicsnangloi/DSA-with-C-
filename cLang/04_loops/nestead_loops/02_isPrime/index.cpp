#include <stdio.h>

int main(){
	int num;
	printf("Enter n : ");
	scanf("%d", &num);
	
	int i = 1;
	while (i <= num){
		int isPrime = 1;
		int ci = i;
		int j = 2;
		while (ci != 1 && i != j){
		if (ci % j == 0){
			isPrime = 0;
			break;
		}
		else{
			j++;
		}
	}
	if (isPrime == 1){
		printf("%d\n", i);
	}
	i++;	
	}
	return 0;
}