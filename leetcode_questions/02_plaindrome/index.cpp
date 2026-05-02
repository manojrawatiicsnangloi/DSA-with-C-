#include <iostream>
using namespace std;
 bool isPalindrome(int x) {
        int rev = 0;
        if (x == 0) return true;
        if ((x % 10 == 0)) return false;
        while (x > rev){
            rev =rev * 10 +  x % 10;
            x /= 10;
        }
        return ((rev == x) || (rev / 10) == x);
    }

int main(){
    cout <<(  isPalindrome(0) == 1) ? "\ntrue" : "\nfalse";
    return 0;
}
