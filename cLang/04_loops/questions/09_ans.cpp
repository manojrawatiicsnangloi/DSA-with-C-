#include <stdio.h>

int main(){
    int num;
	printf("Enter value num");
	scanf("%d", &num);
    int i = 2;

    while (num != 1){
        if (num % i == 0){
            num /= i;
            printf("%d ", i);
        }

        else{
           i++; 
        }
    }
    return 0;
}