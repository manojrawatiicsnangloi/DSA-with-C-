#include <stdio.h>

int main() {
    FILE *f = fopen("abc.txt", "w");

    if (f == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    fprintf(f, "Hello Manoj\n");
    fprintf(f, "This is file writing in C\n");

    fclose(f);
    return 0;
}