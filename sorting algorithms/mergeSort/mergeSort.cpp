// Merge sort
#include <iostream>
using namespace std;
#include <vector>

void merge(int arr [], int left, int mid,int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector <int> leftArr(n1);
    vector <int> rightArr(n2);
        
    for (int i=0; i < n1; i++){
        leftArr[i] = arr[left + i];
    }
    
    for (int i = 0; i < n2; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2){
        if(leftArr[i] <= rightArr[j]){
            arr[k] = leftArr[i];
            k++;
            i++;
        }
        else{
            arr[k] = rightArr[j];
            k++;
            j++;
        }
    } 
    while(i < n1){
        arr[k] = leftArr[i];
        k++;
        i++;
    }
    while( j < n2){
        arr[k] = rightArr[j];
        k++;
        j++;
    }
}

void mergeSort(int arr[], int left, int right){
    if (left >= right){
        return;
    }
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void printArr (int arr[], int size){
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
}

int main() {
    int arr [] = { 12, 32, 43, 14, 98, 45, 50, 51, 55, 59, 60, 78, 89, 88, 85, 1, 2, 4, 5, 6, 7 };
    
    int size = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, size - 1);
    printArr(arr, size);
    return 0;
}






