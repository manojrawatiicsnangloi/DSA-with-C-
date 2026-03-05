#include <iostream>
#include <vector>
int main(){
    std::vector<int> arr = {12, 4, 6, 12, 20, 29, 14};
    int min = arr[0];
    int second_min = arr[0];
    for (int i = 0; i < arr.size(); i++){
        if (min > arr[i]){
            second_min = min;
            min = arr[i];
        }
        else if (second_min > arr[i]){
            second_min = arr[i];
        }
    }
    std::cout << "min Element is " << min << "\n" ;
    std::cout << "Second min Element is " << second_min;
    return 0;
}