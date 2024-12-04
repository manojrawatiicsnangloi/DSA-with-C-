#include <iostream>
using namespace std;

int fibonacci(int cNum){
    if (cNum == 0) {
        return 0;
    }

    if (cNum == 1) {
        return 1;
    }

    return fibonacci(cNum - 1) + fibonacci(cNum - 2);
}

int main() {
    int a;
    cin >> a;
    for (int i = 0; i <= a; i++){
        cout << fibonacci(i) << " ";
    }
    return 0;
}