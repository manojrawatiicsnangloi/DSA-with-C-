#include <iostream>
#include <string>

class User {
public:
    std::string name;
    std::string email;
    int age;

    // Constructor
    User(std::string n, std::string e, int a) {
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
    // constructor automatically runs when object is created
    User u1("Manoj Rawat", "manoj@gmail.com", 21);
    User u2("Rahul Sharma", "rahul@gmail.com", 25);
    u1.printInfo();
    std::cout << std::endl;
    u2.printInfo();
    return 0;
}