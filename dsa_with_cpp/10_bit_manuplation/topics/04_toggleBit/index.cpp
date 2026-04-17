#include <iostream>

int toggleBit(int n , int i){
    return (1 << i) ^ n;
}
int main(){
    std::cout<< toggleBit(13, 2);
    return 0;
}