#include <iostream>
using namespace std;

class Shape {               // Abstract class
public:
    virtual void draw() = 0;  // pure virtual
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing Circle\n";
    }
};

int main() {
    // Shape s; ❌ cannot create abstract class
    Shape* s = new Circle();
    s->draw();
}