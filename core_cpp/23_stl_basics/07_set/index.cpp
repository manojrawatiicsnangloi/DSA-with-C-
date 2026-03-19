#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;

    // 🔹 insert()
    s.insert(10);
    s.insert(5);
    s.insert(20);
    s.insert(10); // duplicate (ignored)

    cout << "Set elements: ";
    for (int x : s) cout << x << " ";
    cout << endl;

    // 🔹 find()
    if (s.find(10) != s.end())
        cout << "10 found\n";
    else
        cout << "10 not found\n";

    // 🔹 count()
    cout << "Count of 5: " << s.count(5) << endl;

    // 🔹 erase()
    s.erase(5);
    cout << "After deleting 5: ";
    for (int x : s) cout << x << " ";
    cout << endl;

    // 🔹 size() & empty()
    cout << "Size: " << s.size() << endl;
    cout << "Is empty: " << (s.empty() ? "Yes" : "No") << endl;

    // 🔹 lower_bound()
    auto lb = s.lower_bound(10);
    if (lb != s.end())
        cout << "Lower bound of 10: " << *lb << endl;

    // 🔹 upper_bound()
    auto ub = s.upper_bound(10);
    if (ub != s.end())
        cout << "Upper bound of 10: " << *ub << endl;

    return 0;
}