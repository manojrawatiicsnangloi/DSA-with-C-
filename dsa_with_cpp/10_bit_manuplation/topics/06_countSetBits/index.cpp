#include <iostream>

int countBit(int n){
    int r = 0;
    while (n != 0){
        if ((n & 1) == 1) {
            r++;
        }
        // std::cout<<n;    
        n = n >> 1;
    }
    return r;
}
int countBitOpt(int n){
    int r = 0;
    while (n != 0){
        if ((n & 1) == 1) {
            r++;
        }
        // std::cout<<n;    
        n = n & (n - 1);
    }
    return r;
}

int main(){
    std::cout<< countBit(13);
    std::cout<< countBitOpt(13);
    return 0;
}