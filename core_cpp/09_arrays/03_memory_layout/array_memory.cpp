#include <iostream>
using namespace std;

int main()
{
    int arr[3] = {10,20,30};
    cout << arr << endl;       // address of arr[0]
    cout << arr+1 << endl;     // address of arr[1]
    cout << arr+2 << endl;     // address of arr[2]
    cout << *(arr) << endl;    // 10
    cout << *(arr+1) << endl;  // 20
    cout << *(arr+2) << endl;  // 30
    return 0;
}