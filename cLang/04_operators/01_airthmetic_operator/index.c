#include <stdio.h>

int main() {
	int l;
	int b;
    printf("Enter a length : ");
    scanf("%d", &l);
    printf("Enter a breadth: ");
    scanf("%d", &b);
    float area = l * b;
    printf("%f", area);
    return 0;
}