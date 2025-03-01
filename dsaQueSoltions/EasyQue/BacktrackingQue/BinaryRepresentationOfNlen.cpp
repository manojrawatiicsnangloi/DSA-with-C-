#include <iostream>

void generateBinary(int n, std::string current) {
    // Base case: when the string length reaches 'n'
    if (current.length() == n) {
        std::cout << current << std::endl;
        return;
    }

    generateBinary(n, current + "0");
    generateBinary(n, current + "1");
}

int main() {
    int a = 4;  // Change this to generate binary numbers of different lengths
    generateBinary(a, "");
    return 0;
}
