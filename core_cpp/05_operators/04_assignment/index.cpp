#include <iostream>
using namespace std;

int main() {

    int a = 10;
    int b = 5;

    cout << "\nAssignment Operators\n";
    int x = 10;
    x += 5;
    cout << "x += 5 -> " << x << endl;

    x -= 3;
    cout << "x -= 3 -> " << x << endl;

    x *= 2;
    cout << "x *= 2 -> " << x << endl;

    x /= 4;
    cout << "x /= 4 -> " << x << endl;
    return 0;
}