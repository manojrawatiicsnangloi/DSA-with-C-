#include <iostream>
using namespace std;

int main(){
    int num;
    cout <<  "enter number";
    cin >> num;
    if ((num & 1) == 0){
        cout << "Even";
    }
    else{
        cout << "Odd";
    }
    return 0;
}