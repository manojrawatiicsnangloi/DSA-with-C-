#include <iostream>
#include <cmath>
#include <string>

std::string changeToBinary(int i){
    if (i == 0){
        return "";
    }
    std::string b = std::to_string(i % 2);
    return b + changeToBinary(i / 2);
}

void printBinary(int ran, int num){
    for (int i = 0; i <= ran; i++){
        std::string binary = changeToBinary(i);
        int len = num - binary.length();
        for (int j = 1; j <= len; j++){
            std:: cout << "0";
        }
        
        std::cout << changeToBinary(i) << "\n";
    }
}
int main() {
    int a = 4;
    int highestNumber = pow(2 , a) - 1;
    printBinary(highestNumber, a);
    std :: cout << highestNumber;
    std::cout << "Try programiz.pro";

    return 0;
}