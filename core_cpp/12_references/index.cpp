#include <iostream>
using namespace std;

int main() {

    int x = 10;

    int &ref = x;   // ref is a reference to x

    cout << "Value of x: " << x << endl;
    cout << "Value using reference: " << ref << endl;

    ref = 20;   // modifying through reference

    cout << "After changing ref" << endl;
    cout << "Value of x: " << x << endl;
    cout << "Value of ref: " << ref << endl;

    return 0;
}