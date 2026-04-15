#include <iostream>

int partion(int arr[], int low, int high){
    int pivote = arr[high];
    int j = low - 1;
    for (int i = low; i <= high; i++){
        if (pivote > arr[i]){
            j++;
            std::swap(arr[j], arr[i]);
        }
    }

    std::swap(arr[j +  1], arr[high]);
    return j + 1;
}


void quick_sort(int arr[], int left, int right){
    if (left < right){
        int pi = partion(arr, left, right);
        quick_sort(arr, left , pi - 1);
        quick_sort(arr, pi + 1, right);
    }
}

void printArr(int arr[], int size){
    for (int i = 0; i < size; i++){
        std::cout << arr[i] << " ";
    }
}

int main(){
    int arr [] = {1, 32, 2, 56, 7, 8, 12, 4, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    quick_sort(arr, 0, size - 1);
    printArr(arr, size);   
    return 0;
}
