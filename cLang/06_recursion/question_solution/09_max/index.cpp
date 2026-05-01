// Online C compiler to run C program online
#include <stdio.h>

int max(int arr[], int i, int m, int size){
    if (size == i ){
        printf("%d", m);
    }
    if (i < size){
           if (m < arr[i]){
               m = arr[i];
           }
           max(arr, i + 1, m, size);
    }
}


int main() {
    // printf("%d", c(123));
    int arr[] = {1, 2, 3, 14, 5, 6, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    max(arr, 0, arr[0], size);
    return 0;
}













