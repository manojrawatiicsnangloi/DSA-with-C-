
#include <stdio.h>

int main(){
	int a;
	float n1;
	double n2;
	char ch;
	// bool isValid;
	char name [100];
	
	printf("Enter value of a : ");
	scanf("%d", &a);
	
	printf("Enter value of n1 : ");
	scanf("%f", &n1);
	
	printf("Enter value of n2 : ");
	scanf("%lf", &n2);
	
	printf("Enter value of ch : ");
	scanf(" %c", &ch);
	
	printf("Enter value of name : ");
	scanf("%s", name);
	
	printf("Enter value of is Valid : ");
	// scanf("%d", &isValid);

	printf("value of a is : %d\n", a);
	printf("value of n1 is : %.15f\n", n1);
	printf("value of n2 is : %.15lf\n", n2);
	printf("value of ch is : %c hello \n", ch);
	// printf("value of isValid is : %d\n", isValid);
	printf("value of name is : %s\n", name);
	
	return 0;
}