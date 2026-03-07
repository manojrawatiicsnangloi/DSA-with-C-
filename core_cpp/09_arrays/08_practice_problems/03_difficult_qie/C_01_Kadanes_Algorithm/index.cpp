#include <iostream>
#include <vector>

int main(){
    // std::vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    // int max_sum = 0;
    // for (int i = 0; i < arr.size(); i++){
    //     int cur_sum = 0;
    //     for (int j = i; j < arr.size(); j++){
    //         cur_sum += arr[j];
    //         if (cur_sum > max_sum){
    //             max_sum = cur_sum;
    //         }
    //     }
    // }
    // std::cout << max_sum;
    
    std::vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    int current_sum = 0;
    int max_sum = 0;
    for (int x : arr){
        current_sum += x;
        if (current_sum > max_sum){
            max_sum = current_sum;
        }
        if (current_sum < 0){
            current_sum = 0;
        }
    }
    std::cout << max_sum;
    return 0;
}