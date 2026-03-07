#include <iostream>
using namespace std;

int main() {
    int x = 5;
    int* ptr = &x;
    int** pptr = &ptr;
    cout << x << endl;
    cout << *ptr << endl;
    cout << **pptr << endl;

}