#include <iostream>

int main(){
    std::cout << "Enter array size";
    int x;
    std::cin >> x;
    int arr [x];
    for (int i = 0; i < x; i++){
        std::cin >> arr[i];
    }
    for (int i = 0; i < x; i++){
        std::cout << arr[i] << ", ";
    }

    return 0;
}