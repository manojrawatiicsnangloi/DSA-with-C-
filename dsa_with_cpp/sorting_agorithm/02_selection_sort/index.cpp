#include <iostream>

void selectionSort(int arr[], int size){
    for (int i = 0; i < size; i++){
        int min = i;
        for (int j = i + 1; j< size; j++){
            if (arr[min] > arr[j]){
                min = j;
            }
        }
        
        if (min != i){
            std::swap(arr[min], arr[i]);
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
    selectionSort(arr, size);
    printArr(arr, size);

    return 0;
}

