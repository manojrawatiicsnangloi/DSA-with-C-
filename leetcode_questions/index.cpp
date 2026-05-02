#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp; // number -> index

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];

        if (mp.find(complement) != mp.end()) {
            return {mp[complement], i};
        }

        mp[nums[i]] = i;
    }
    return {}; // no solution
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> sol = twoSum(arr, 9);
    for (int i : sol){
        cout << i  << " ";
    }
    cout << "\n";
    return 1;
}