#include <stdio.h>

int main() {
    FILE *f = fopen("abc.txt", "a");

    if (f == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    fprintf(f, "This line is appended\n");

    fclose(f);
    return 0;
}