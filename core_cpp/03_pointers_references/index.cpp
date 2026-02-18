#include <iostream>

int main() {
    int x = 10;
    int * ptr = &x;
    std::cout << "Value of x: " << x << std::endl;
    std::cout << "Address of x: " << &x << std::endl;
    std::cout << "Value stored in ptr : " << ptr << std::endl;
    std::cout << "Value at address stored in ptr :  " << *ptr << std::endl;
    return 0;
}
