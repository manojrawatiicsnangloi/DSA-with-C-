#include <iostream>

int clearBit(int n , int i){
    return ~(1 << i) & n;
}
int main(){
    std::cout<< clearBit(13, 2);
    return 0;
}