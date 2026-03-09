#include <iostream>
#include <vector>

int main(){
    std::vector<int> arr = {1, 2, 3, 4, 5};
    int i = 0;
    while (i < arr.size()){
        if (arr[i] % 2 == 0){
            arr.erase(arr.begin() + i);
        }
        i++;
    }
    for (int i : arr){
        std::cout << i;
    }
    return 0;
}