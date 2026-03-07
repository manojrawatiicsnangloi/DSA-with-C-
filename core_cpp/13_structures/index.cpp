#include <iostream>

struct user{
    std::string name;
    std::string email;
    int age;

    void getInfo(){
        std::cout << "Name :" << name <<std::endl;
        std::cout << "Name :" << email << std::endl;
        std::cout << "Name :" << name << std::endl;
    }
};

int main(){
    user u1;
    u1.name = "Manoj Rawat";
    u1.email = "manoj@gmail.com";
    u1.age = 21;
    u1.getInfo();
    return 0;
}