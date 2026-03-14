#include <iostream>
#include <vector>
#include <stack>

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

int getMaxAreaOptimize(std::vector<int>& arr) {
    int n = arr.size();
    std::stack<int> st;
    int max_area = 0;

    for (int i = 0; i <= n; i++) {
        int height = (i == n) ? 0 : arr[i];

        while (!st.empty() && height < arr[st.top()]) {
            int h = arr[st.top()];
            st.pop();

            int right = i;
            int left = st.empty() ? -1 : st.top();

            int width = right - left - 1;
            int area = h * width;

            max_area = std::max(max_area, area);
            if (i == 1){
                std::cout << "max area" << max_area << "\n";
            }
        }

        st.push(i);
    }

    return max_area;
}
int main(){
    std::vector<int> arr = {2, 1, 1};


    std::cout << getMaxAreaOptimize(arr);
    // std::cout << getMaxArea(arr);
    return 0;
}