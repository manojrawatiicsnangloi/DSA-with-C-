#include <iostream>
#include <vector>
int main(){
    std::vector<int> arr = {12, 4, 6, 12, 20, 29, 4};
    bool isSort = true;
    for (int i = 1; i < arr.size(); i++){
        if (arr[i] < arr[i-1]){
            isSort = false;
        }
    }
    isSort ? std::cout << "Sorted" : std::cout<< " not sort";
    return 0;
}