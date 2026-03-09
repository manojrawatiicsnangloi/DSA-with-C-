#include <iostream>
#include <vector>

int main(){
    std::vector<int> arr = {1, 2, 3, 4, 5};
    while (!arr.empty()){
        std::cout << arr.back() << " Removed";
        arr.pop_back();
    }
    return 0;
}