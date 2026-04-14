#include <iostream>

void insertionSort(int arr[], int size){
    for (int i = 1; i < size; i++){
        int j = i - 1;
        int curr = arr[i];
        while (j >= 0 && arr[j] > curr){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = curr;
    }
}

void printArr(int arr[], int size){
    for (int i = 0; i < size; i++){
        std::cout << arr[i] << " ";
    }
}

int main(){
    int arr[] = {21, 23, 43, 1, 98, 76, 54, 88, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, size);
    printArr(arr, size);

    return 0;
}