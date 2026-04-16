#include <stdio.h>

int main(){
	int i = 1;
	int s = 0;
	while (i <= 50){
		s += i;
		i++;
	}
	printf("%d", s);
	return 0;
}
