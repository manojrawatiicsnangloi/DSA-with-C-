// Insertion sort
#include <iostream>
using namespace std;


void insertionSort(int arr[], int size){
    for (int i = 1; i < size; i++){
        int temp = arr[i];
        int j = i;
        while(j > 0 && arr[j - 1] > temp){
            arr[j] = arr[j - 1];
            j = j -1;
    }
        arr[j] = temp;
    }
}

void printArr (int arr[], int size){
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
}

int main() {
    int arr [] = { 12, 32, 43, 14, 98, 45, 50, 51, 55, 59, 60, 78, 89, 88, 85, 1, 2, 4, 5, 6, 7 };
    int size = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, size);
    printArr(arr, size);
    return 0;
}






