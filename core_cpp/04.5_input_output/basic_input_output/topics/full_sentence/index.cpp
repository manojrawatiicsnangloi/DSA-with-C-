#include <iostream>


int main(){
    std::string x;
    std::cout << "Please Enter ";
    getline(std::cin, x);
    std::cout << "You Enter " << x;
    return 0;

}