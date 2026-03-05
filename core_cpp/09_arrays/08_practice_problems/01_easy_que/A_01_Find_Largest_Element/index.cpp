#include <iostream>
#include <vector>
int main(){
    std::vector<int> arr = {12, 4, 6, 12, 20, 29, 4};
    int max = arr[0];
    int second_max = arr[0];
    for (int i = 0; i < arr.size(); i++){
        if (max < arr[i]){
            second_max = max;
            max = arr[i];
        }
        else if (second_max < arr[i]){
            second_max = arr[i];
        }
    }
    std::cout << "Max Element is " << max << "\n" ;
    std::cout << "Second max Element is " << second_max;
    return 0;
}