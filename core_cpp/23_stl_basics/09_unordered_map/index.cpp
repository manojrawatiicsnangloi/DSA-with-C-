#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int, string> m;

    // 🔹 insert()
    m.insert({1, "One"});
    m.insert({2, "Two"});

    // 🔹 operator[] (insert + update)
    m[3] = "Three";     // insert
    m[2] = "Updated";   // update

    // 🔹 display (order NOT guaranteed)
    cout << "Unordered Map elements:\n";
    for (auto p : m) {
        cout << p.first << " : " << p.second << endl;
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

    // 🔹 clear()
    m.clear();
    cout << "After clear, is empty: " << (m.empty() ? "Yes" : "No") << endl;

    return 0;
}