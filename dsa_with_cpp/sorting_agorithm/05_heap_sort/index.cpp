#include <iostream>

    void heapify(int arr[], int i, int size){
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;
        if (left < size && arr[left] > arr[largest]){
            largest = left;
        }
        
        if (right < size && arr[right] > arr[largest]){
            largest = right;
        }

        if (largest != i){
            std::swap(arr[largest], arr[i]);
            heapify(arr, largest, size);
        }
    }

void buildMaxHeap(int arr[], int size){
        
    for (int i = size / 2 - 1; i >= 0; i--) {
            heapify(arr, i, size);
    }

    for (int i = size - 1; i >= 0; i--){
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            heapify(arr, 0, i);
    }
    }
int main(){

    return 0;
}