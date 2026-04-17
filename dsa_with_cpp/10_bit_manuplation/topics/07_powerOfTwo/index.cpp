#include <iostream>

bool
 isPowerOfTwo(int n){
    return n & (n - 1) == 0;
}

int main(){
    std::cout<< isPowerOfTwo(13);
    return 0;
}