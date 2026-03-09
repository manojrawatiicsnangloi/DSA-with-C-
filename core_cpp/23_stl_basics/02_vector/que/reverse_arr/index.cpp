#include <iostream>
#include <vector>

int main(){
    std::vector<int> arr = {1, 2, 3, 4, 5};
    int left = 0;
    int right = arr.size() - 1;
    while (left < right){
        std::swap(arr[left], arr[right]);
        right--;
        left++;
    }
    for (int i : arr){
        std::cout << i;
    }
    return 0;
}