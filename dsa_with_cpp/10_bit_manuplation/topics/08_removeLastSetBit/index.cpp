#include <iostream>

int isPowerOfTwo(int n){
    return n & (n - 1);
}

int main(){
    std::cout<< isPowerOfTwo(13);
    return 0;
}