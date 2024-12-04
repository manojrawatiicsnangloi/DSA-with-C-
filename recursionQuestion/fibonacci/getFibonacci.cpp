#include <iostream>
using namespace std;

int fibonacci(int i){
    if (i == 1) {
        return 0;
    }
    
    if (i == 2) {
        return 1;
    }
    return fibonacci(i - 1) + fibonacci(i - 2);
}

int main() {
    int a;
    cin >> a;
    int fib = fibonacci(a);
    cout << fib;
    return 0;
}