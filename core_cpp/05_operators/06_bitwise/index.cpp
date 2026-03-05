#include <iostream>
using namespace std;

int main() {

    int a = 10;
    int b = 5;


    cout << "\nBitwise Operators\n";
    cout << "a & b : " << (a & b) << endl;
    cout << "a | b : " << (a | b) << endl;
    cout << "a ^ b : " << (a ^ b) << endl;
    cout << "~a    : " << (~a) << endl;
    cout << "a << 1: " << (a << 1) << endl;
    cout << "a >> 1: " << (a >> 1) << endl;

    return 0;
}