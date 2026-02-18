#include <iostream>

void stackFunction() {
    int a = 100;   // Stored in stack
    std::cout << "Inside function (stack variable a): " << a << std::endl;
}

int main() {

    // 🔹 STACK MEMORY
    int x = 10;  
    std::cout << "Stack variable x: " << x << std::endl;
    std::cout << "Address of x (stack): " << &x << std::endl;
    // 🔹 HEAP MEMORY
    int* ptr = new int;   // allocated on heap
    *ptr = 20;
    std::cout << "Heap value (*ptr): " << *ptr << std::endl;
    std::cout << "Address stored in ptr (heap location): " << ptr << std::endl;
    std::cout << "Address of ptr itself (stack): " << &ptr << std::endl;
    delete ptr;  // free heap memory
    stackFunction();  // function call → new stack frame
    return 0;
}
 