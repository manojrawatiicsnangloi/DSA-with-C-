#include <iostream>
using namespace std;

class User {
public:
    static int count;   // static member

    User() {
        count++;
    }

    static int getCount(){
        return count;
    }
};

int User::count = 0;   // static variable definition

int main() {

    User u1;
    User u2;
    User u3;

    cout << "Total objects created: " << User::count << endl;

}