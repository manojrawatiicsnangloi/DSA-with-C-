#include <iostream>
using namespace std;

int main() {
    int i;
    float f;
    double d;
    char c;
    string s;
    bool b;

    // Taking input
    cout << "Enter an integer: ";
    cin >> i;

    cout << "Enter a float: ";
    cin >> f;

    cout << "Enter a double: ";
    cin >> d;

    cout << "Enter a character: ";
    cin >> c;

    cout << "Enter a string: ";
    cin >> s;

    cout << "Enter a boolean (0 or 1): ";
    cin >> b;

    // Printing output
    cout << "\n--- Output ---" << endl;
    cout << "Integer: " << i << endl;
    cout << "Float: " << f << endl;
    cout << "Double: " << d << endl;
    cout << "Character: " << c << endl;
    cout << "String: " << s << endl;
    cout << "Boolean: " << b << endl;

    return 0;
}