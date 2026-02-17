#include <iostream>
using namespace std;

int factorial(int cNum){
    if (cNum == 1) {
        return 1;
    }
    return cNum * factorial(cNum - 1);
}

int main() {
    int a;
    cin >> a;
    cout << factorial(a) << " ";
    return 0;
}