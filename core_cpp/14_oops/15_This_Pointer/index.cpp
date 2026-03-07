#include <iostream>

class A {
public:
    int x;

    void set(int x) {
        this->x = x;
    }
};

int main(){
    A a;
    a.set(12);
    return 0;
}