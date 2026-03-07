#include <iostream>
#include <string>
// #include <algorithm>

using namespace std;

int main() {

    // 1. Creating Strings
    string s1 = "Hello";
    string s2 = "World";

    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;

    // 2. Concatenation
    string s3 = s1 + " " + s2;
    cout << "Concatenation: " << s3 << endl;

    // 3. Length
    cout << "Length of s3: " << s3.length() << endl;

    // 4. Access Characters
    cout << "First character: " << s3[0] << endl;

    // 5. Substring
    cout << "Substring (0,5): " << s3.substr(0,5) << endl;

    // 6. Find
    cout << "Position of 'World': " << s3.find("World") << endl;

    // 7. Append
    s1.append(" C++");
    cout << "Append: " << s1 << endl;

    // 8. Reverse
    string rev = s3;
    // reverse(rev.begin(), rev.end());
    cout << "Reversed: " << rev << endl;

    // 9. Palindrome Check
    string str = "madam";
    string temp = str;
    // reverse(temp.begin(), temp.end());

    if(str == temp)
        cout << str << " is Palindrome" << endl;
    else
        cout << str << " is Not Palindrome" << endl;

    // 10. Iterate through string
    cout << "Characters in s3: ";
    for(char c : s3){
        cout << c << " ";
    }
    cout << endl;

    return 0;
}