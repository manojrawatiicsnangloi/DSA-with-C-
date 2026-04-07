#include <stdio.h>

int main() {
    int i;
    float f;
    double d;
    char c;
    char s[100];   // string (array of characters)
    int b;         // boolean (C uses int for boolean)

    // Taking input
    printf("Enter an integer: ");
    scanf("%d", &i);

    printf("Enter a float: ");
    scanf("%f", &f);

    printf("Enter a double: ");
    scanf("%lf", &d);

    printf("Enter a character: ");
    scanf(" %c", &c);   // space before %c to avoid newline issue

    printf("Enter a string: ");
    scanf("%s", s);

    printf("Enter a boolean (0 or 1): ");
    scanf("%d", &b);

    // Printing output
    printf("\n--- Output ---\n");
    printf("Integer: %d\n", i);
    printf("Float: %f\n", f);
    printf("Double: %lf\n", d);
    printf("Character: %c\n", c);
    printf("String: %s\n", s);
    printf("Boolean: %d\n", b);

    return 0;
}