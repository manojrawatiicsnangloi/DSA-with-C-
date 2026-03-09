#include <iostream>
#include <vector>

int main(){
    std::vector<int> arr = {0, 1, 3, 4, 5};
    int i = 2;
    arr.insert(arr.begin() + 2, 2);
    for (int i :  arr){
        std::cout << i;
    }
    return 0;
}