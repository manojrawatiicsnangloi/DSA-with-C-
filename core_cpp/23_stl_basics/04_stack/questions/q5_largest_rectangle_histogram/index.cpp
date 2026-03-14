#include <iostream>
#include <vector>

int getMaxArea(std::vector<int> arr){
    int size = arr.size();
    int max_area = 0;
    for (int i = 0; i < size; i++){
        int left = i;
        int height = arr[left];
        while (left >= 0 && height <= arr[left]){
            left--;
        }
        int right = i;
        while (i < size && height <= arr[right]){
            right++;
        }
        int width = right - left - 1;
        int area = width * height;
        if (area == 20){
            std::cout << "left : " << left << " Right : " << right << " Index " << i << "\n";
        }
        max_area = std::max(area, max_area); 
    }
    return max_area;
} 
int main(){
    std::vector<int> arr = {2, 1, 5, 6, 2, 3};
    std::cout << getMaxArea(arr);
    return 0;
}