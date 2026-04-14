#include <iostream>

void bubbleSort(int arr[], int size){
    for (int i = 0; i < size - 1; i++){        
        for (int j = 0; j< size - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                std::swap(arr[j], arr[j + 1]);
            }
        }
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
    bubbleSort(arr, size);
    printArr(arr, size);

    return 0;
}

