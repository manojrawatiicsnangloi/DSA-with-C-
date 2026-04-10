#include <stdio.h>

int main() {
	int r;
    printf("Enter a radius: ");
    scanf("%d", &r);
    float area = 3.14 * r * r;
    printf("%f", area);
    return 0;
}