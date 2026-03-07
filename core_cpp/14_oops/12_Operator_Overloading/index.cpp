#include <iostream>

class Complex {
public:
    int real, imag;

    Complex(int r, int i) {
        real = r;
        imag = i;
    }

    Complex operator+(Complex c) {
        return Complex(real + c.real, imag + c.imag);
    }
};

int main(){
    Complex x(1, 3);
    Complex y(4, 8);
    Complex z = x + y;
    std::cout << z.real;
    std::cout << z.imag;

    return 0;
}