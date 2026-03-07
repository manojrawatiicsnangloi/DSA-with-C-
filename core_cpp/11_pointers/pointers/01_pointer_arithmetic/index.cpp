#include <iostream>
using namespace std;

int main()
{
    int arr[] = {10, 20, 30, 40};
    int *ptr = arr;
    cout << " ptr - " << ptr << endl;
    cout << " &arr - " << &arr << endl;
    cout << "*ptr - " << *ptr << endl;
    cout << "*(ptr + 1) - " << *(ptr + 1) << endl;
    cout << "*(ptr + 2) - " << *(ptr + 2) << endl;
}