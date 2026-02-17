#include <iostream>
using namespace std;

int findSum (int arr[], int size, int currentIndex){
    if (currentIndex >= size){
        return 0;
    }
    return arr[currentIndex] + findSum(arr, size, currentIndex + 1);
}
int main() {
    int arr [] = {23, 45, 54,10, 11, 43, 91};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << findSum(arr, size, 0);
    return 0;
}