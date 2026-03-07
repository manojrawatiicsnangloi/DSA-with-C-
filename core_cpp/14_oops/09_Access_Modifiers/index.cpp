#include <iostream>
using namespace std;

class Person {
private:
    int salary;          // private → only accessible inside this class

protected:
    int age;             // protected → accessible in child classes

public:
    string name;         // public → accessible everywhere

    void setSalary(int s) {
        salary = s;
    }

    int getSalary() {
        return salary;
    }
};

class Employee : public Person {
public:
    void setAge(int a) {
        age = a;        // allowed because age is protected
    }

    void showInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Salary: " << getSalary() << endl;
    }
};

int main() {

    Employee e;

    e.name = "Manoj";      // public → accessible
    e.setAge(21);          // protected accessed through child function
    e.setSalary(50000);    // private accessed through public function

    e.showInfo();

    // e.salary = 50000;   ❌ not allowed (private)
    // e.age = 21;         ❌ not allowed (protected)

    return 0;
}