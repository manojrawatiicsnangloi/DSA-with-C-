#include <iostream>

class Array {
private:
    int* data;

public:
    Array(int size) {
        data = new int[size];
        std::cout << "Memory allocated\n";
    }

    ~Array() {
        delete[] data;
        std::cout << "Memory freed\n";
    }
};

int main() {
    Array arr(5);
}