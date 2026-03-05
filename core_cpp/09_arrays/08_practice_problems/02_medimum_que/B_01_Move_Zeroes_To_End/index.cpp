#include <iostream>
#include <vector>

int main()
{
    std::vector<int> arr = {12, 4, 0, 0, 20, 29, 4};
    int left = 0;
    int right = arr.size() - 1;
    while (left < right){
        if (arr[left] == 0){
            std::swap(arr[left], arr[right]);
            right--;    
        }
        else{
            left++;
        }
    }

    for (int i : arr){
        std::cout << i << ", ";
    }
    return 0;
}