#include <iostream>
using namespace  std;

int main(){
    int i = 3;
    int n;
    cout << "Enter number : ";
    
    cin >> n;
    if (n&(1<<i) != 0){
        cout << i << "th bit is on";
    }
    else {
        cout << i  << "th bit is off";
    }
    return 0;
}