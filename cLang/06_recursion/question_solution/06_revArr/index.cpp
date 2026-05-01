// Online C compiler to run C program online
#include <stdio.h>


void rev(int arr[], int l, int r){
    if (l < r){
        int temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;
        rev(arr, l + 1, r - 1);
    }
}

void p(int arr[], int size){
    for (int i = 0; i < size;i++){
        printf("%d ", arr[i]);
    }
}


int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    rev(arr, 0, size - 1);
    p(arr,size);
    // Write C code here
    // printf("%d", fib(10));

    return 0;
}