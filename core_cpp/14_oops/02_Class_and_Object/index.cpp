#include <iostream>
#include <string>

class User {
public:
    std::string name;
    std::string email;
    int age;

    void setInfo(std::string n, std::string e, int a) {
        name = n;
        email = e;
        age = a;
    }

    void printInfo() {
        std::cout << "Name  : " << name << std::endl;
        std::cout << "Email : " << email << std::endl;
        std::cout << "Age   : " << age << std::endl;
    }
};

int main() {

    // creating objects
    User u1;
    User u2;

    // assigning values using member function
    u1.setInfo("Manoj Rawat", "manoj@gmail.com", 21);
    u2.setInfo("Rahul Sharma", "rahul@gmail.com", 25);

    // calling functions
    u1.printInfo();
    std::cout << std::endl;
    u2.printInfo();

    return 0;
}