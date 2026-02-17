// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

void heapify(int arr [], int size, int i){
    int largest = i;
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    
    if (left < size && arr[left] > arr[largest]){
        largest = left;
    }
    
    if (right < size && arr[right ] > arr[largest]){
        largest = right;
    }
    
    if (largest != i){
        int temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;
        heapify(arr, size, largest);
    }
}

void buildMaxHeap(int arr [], int size){
    for (int i = size / 2 - 1; i >= 0; i--){
        heapify(arr, size, i);
    }
}

void printArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
}

int main() {
    int arr [] = { 23, 45, 56, 76, 12, 54, 13, 30, 40, 43, 78, 99, 122,333};
    int size = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, size);
    buildMaxHeap(arr, size);
    cout << " \n";
    printArray(arr, size);
    return 0;
}