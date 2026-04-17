#include <iostream>

int setBit(int n , int i){
    return (1 << i) | n;
}
int main(){
    std::cout<< setBit(9, 2);
    return 0;
}