#include <stdio.h>

int main(){
	int num = 12;
	int i = 1;
	while (i <= num){
		int j = 1;
		printf("----------Table of %d -----------------\n", i);
		while (j <= 10){
			printf("%d * %d = %d\n", i, j, i * j);
			j++;	
		}
		i += 1;
	}
	return 0;
}