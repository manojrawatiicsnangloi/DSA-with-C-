#include <iostream>

class User {
public:
    std::string name;
    std::string email;
    int age;

    void getInfo() {
        std::cout << "Name  : " << name << std::endl;
        std::cout << "Email : " << email << std::endl;
        std::cout << "Age   : " << age << std::endl;
    }
};

int main() {
    // creating object
    User u1;
    // assigning values
    u1.name = "Manoj Rawat";
    u1.email = "manoj@gmail.com";
    u1.age = 21;
    // calling member function
    u1.getInfo();
    return 0;
}