#include <iostream>
#include <array>
using namespace std;

int main(){

    array<int,5> arr = {10,20,30,40,50};

    for(int i=0;i<arr.size();i++){
        cout << arr[i] << " ";
    }
}