#include <iostream>
#include <vector>
int main(){
    std::vector<int> arr = {12, 4, 6, 12, 20, 29, 4};
    int sum = 0;
    for (int i = 0; i < arr.size(); i++){
        sum += arr[i];
    }
    std::cout << "Max Element is " << sum << "\n" ;
    return 0;
}