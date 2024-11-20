#include <iostream>
using namespace std;

int binarySearch(int arr [], int left, int right, int target){
        int mid = left + (right - left) / 2;
        
        if (target == arr[mid]){
            return mid;
        }
        
        if (target > arr[mid]){
            return binarySearch(arr, mid + 1, right, target);
        }
        
        if (target < arr[mid]){
            return binarySearch(arr, left, mid - 1, target);        
        }
        
        return -1;
}

void executeSearch(int arr [], int size, int target){
    int targetIndex = binarySearch(arr, 0, size - 1, target);
    cout << "Element found at index : " << targetIndex;
}


int main(){
    int arr [] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 29, 30, 31, 32, 33, 34,  35, 36, 37, 38, 39, 40};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;
    
    cout << "Enter the element you want to search";
    cin >> target;
    executeSearch(arr, size, target);
    cout << "Try programiz.pro";
    return 0;
}












