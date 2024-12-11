#include <iostream>
using namespace std;

void findMinIndex(int arr[], int size, int currentIndex, int minIndex) {
    if (currentIndex >= size) {
        cout << "Element Found at " << minIndex;
        return;
    }
    
    if (arr[currentIndex] < arr[minIndex]) {
        findMinIndex(arr, size, currentIndex + 1, currentIndex);
    } else {
        findMinIndex(arr, size, currentIndex + 1, minIndex);
    }
}

int main() {
    int arr[] = {23, 45, 54, 10, 11, 43, 91};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    if (size == 0) {
        cout << "Array is empty!";
        return 0;
    }
    
    findMinIndex(arr, size, 0, 0);
    return 0;
}
