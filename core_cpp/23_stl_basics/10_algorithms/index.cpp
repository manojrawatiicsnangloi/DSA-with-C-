#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    vector<int> v = {5, 2, 8, 2, 1, 5, 10};
    // 1. Sort
    sort(v.begin(), v.end());

    // 2. Remove duplicates
    v.erase(unique(v.begin(), v.end()), v.end());

    // 3. Print array
    cout << "Array: ";
    for(int x : v) cout << x << " ";
    cout << endl;

    // 4. Find element
    int target = 5;
    if(binary_search(v.begin(), v.end(), target)) {
        cout << target << " exists\n";
    } else {
        cout << target << " not found\n";
    }
    // 5. Min & Max
    int mn = *min_element(v.begin(), v.end());
    int mx = *max_element(v.begin(), v.end());

    cout << "Min: " << mn << endl;
    cout << "Max: " << mx << endl;

    // 6. Sum
    int sum = accumulate(v.begin(), v.end(), 0);
    cout << "Sum: " << sum << endl;

    return 0;
}