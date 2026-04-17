#include <iostream>

int getBit(int n , int i){
    return (n >> i) & 1;
}
int main(){
    std::cout<< getBit(14, 2);
    return 0;
}