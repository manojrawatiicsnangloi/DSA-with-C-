#include <iostream>
using namespace std;

class Animal {
public:
    virtual void sound() {      // virtual function
        cout << "Animal makes sound\n";
    }
};

class Dog : public Animal {
public:
    void sound() override {     // override base class
        cout << "Dog barks\n";
    }
};

int main() {
    Animal* a;      // base class pointer
    Dog d;

    a = &d;         // points to Dog
    a->sound();     // calls Dog::sound due to virtual
}