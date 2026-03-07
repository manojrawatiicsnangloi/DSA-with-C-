#include <iostream>
#include <vector>

int main()
{
    std::vector<int> arr = {1, 1, 2, 2, 3, 4, 4};
      int i = 0;
       for (int j = 1; j < arr.size(); j++){
        if (arr[j] != arr[i]){
            i++;
            arr[i] = arr[j];
        }
       }
    
    for (int j = 0; j <= i; j++){
        std::cout << arr[j] << ", ";
    }
    return 0;
}