#include <stdio.h>

int main(){
    int num;
    
	printf("Enter value num");
	scanf("%d", &num);
    int cn = num;
    int i = 2;
    int isPrime = 1;
    while (num != 1 && cn != i){
        if (num % i == 0){
            isPrime = 0;
            break;
        }
        else{
           i++; 
        }
    }

    if (isPrime == 1){
        printf("This is prime number");
    }
    else{
        printf("This is not     prime number");
    }
    return 0;
}