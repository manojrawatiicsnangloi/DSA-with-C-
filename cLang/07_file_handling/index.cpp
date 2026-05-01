#include <stdio.h>


int main(){
    FILE * f;
    char ch[100];
    f = fopen("abc.txt", "r");
    while (fgets(ch, 100, f) != NULL){
        printf("%s", ch);
    }
    return 0;
}