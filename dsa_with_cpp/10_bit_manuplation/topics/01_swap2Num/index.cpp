#include <iostream>
using namespace std;


int main(){
    int a = 12;
    int b = 13;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout << "a : " << a << "b : " << b;
    return 0;
}