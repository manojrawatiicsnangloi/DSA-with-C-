#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class monotonicStack {
private:
    stack<int> st; // stores indices

public:
    vector<int> nextGreater(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++) {

            while (!st.empty() && arr[st.top()] < arr[i]) {
                ans[st.top()] = arr[i];
                st.pop();
            }

            st.push(i);
        }

        return ans;
    }
};

int main() {
    monotonicStack ms;

    vector<int> arr = {2, 1, 2, 4, 3};
    vector<int> res = ms.nextGreater(arr);

    for (int x : res) {
        cout << x << " ";
    }

    return 0;
}