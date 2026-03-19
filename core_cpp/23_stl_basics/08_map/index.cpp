#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, string> m;

    // 🔹 insert()
    m.insert({1, "One"});
    m.insert({2, "Two"});

    // 🔹 operator[]
    m[3] = "Three";     // insert
    m[2] = "Updated";   // update

    // 🔹 display (using begin() & end())
    cout << "Map elements:\n";
    for (auto it = m.begin(); it != m.end(); it++) {
        cout << it->first << " : " << it->second << endl;
    }

    // 🔹 find()
    if (m.find(2) != m.end())
        cout << "Key 2 found\n";

    // 🔹 count()
    cout << "Count of key 1: " << m.count(1) << endl;

    // 🔹 erase()
    m.erase(1);
    cout << "After deleting key 1:\n";
    for (auto p : m) {
        cout << p.first << " : " << p.second << endl;
    }

    // 🔹 size() & empty()
    cout << "Size: " << m.size() << endl;
    cout << "Is empty: " << (m.empty() ? "Yes" : "No") << endl;

    // 🔹 lower_bound()
    auto lb = m.lower_bound(2);
    if (lb != m.end())
        cout << "Lower bound of 2: " << lb->first << endl;

    // 🔹 upper_bound()
    auto ub = m.upper_bound(2);
    if (ub != m.end())
        cout << "Upper bound of 2: " << ub->first << endl;

    return 0;
}