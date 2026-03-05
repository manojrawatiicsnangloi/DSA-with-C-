#include <iostream>
#include <vector>
using namespace std;

int main(){

    vector<int> v;
    
    // inserting elements
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    // accessing elements like array
    cout << "First element: " << v[0] << endl;
    cout << "Second element: " << v[1] << endl;
    cout << "Third element: " << v[2] << endl;

    // updating element
    v[1] = 10;

    cout << "After update:" << endl;
    cout << v[0] << " " << v[1] << " " << v[2] << endl;

    // size of vector
    cout << "Size of vector: " << v.size() << endl;

    // looping through vector
    cout << "Looping elements: ";
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }

    cout << endl;

    // removing last element
    v.pop_back();

    cout << "After pop_back: ";
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }

    cout << endl;

    return 0;
}