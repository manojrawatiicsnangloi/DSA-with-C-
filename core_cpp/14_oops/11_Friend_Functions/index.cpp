#include <iostream>
using namespace std;

class Box
{
private:
    int length;

public:
    Box(int l)
    {
        length = l;
    }

    // declaring friend function
    friend void printLength(Box b);
};

// friend function definition
void printLength(Box b)
{
    cout << "Length is: " << b.length << endl; // accessing private member
}

int main()
{

    Box b1(10);

    printLength(b1); // calling friend function
}