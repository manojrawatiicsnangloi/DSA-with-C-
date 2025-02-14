// Bubble Sort
#include <iostream>
using namespace std;


void bubbleSort(int arr [], int size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size - 1 - i; j++){
            if (arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp; 
            }
        }
    }
}

void printArr(int arr[], int size){
    for (int i = 0 ;i < size; i++){
        cout << arr[i] << " ";
    }
}

int main() {
    int arr [] = {45, 35, 87, 64, 36, 98, 100, 42, 1, 3, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, size);
    printArr(arr, size);
    return 0;
}