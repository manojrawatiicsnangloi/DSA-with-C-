#include <iostream>
#include <vector>

int main()
{
    std::vector<int> arr = {12, 4, 6, 12, 20, 29, 4};
    int left = 0;
    int right = arr.size() - 1;
    while (left < right){
        std::swap(arr[left], arr[right]);
        left++;
        right--;    
    }

    for (int i : arr){
        std::cout << i << ", ";
    }
    return 0;
}