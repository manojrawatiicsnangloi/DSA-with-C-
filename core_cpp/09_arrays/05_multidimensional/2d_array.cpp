#include <iostream>

int main(){
    int arr [3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8 , 9}}; 
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++){
        int i_size = sizeof(arr[i]) / sizeof(arr[i][0]);
        for (int j = 0; j < i_size; j++){
            std::cout << arr[i][j] << " "; 
        }
        std::cout << " \n";
    }
    return 0;
}