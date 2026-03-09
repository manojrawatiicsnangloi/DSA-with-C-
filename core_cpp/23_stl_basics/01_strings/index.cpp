#include <iostream>
#include <string>

int main() {

    // Creating strings
    std::string s1 = "Hello";
    std::string s2 = "World";

    // Concatenation
    std::string s3 = s1 + " " + s2;
    std::cout << "Concatenated: " << s3 << std::endl;

    // Length
    std::cout << "Length: " << s3.length() << std::endl;

    // Access characters
    std::cout << "First character: " << s3[0] << std::endl;

    // Append
    s3.append(" !!!");
    std::cout << "After append: " << s3 << std::endl;

    // Insert
    s3.insert(5, ",");
    std::cout << "After insert: " << s3 << std::endl;

    // Erase
    s3.erase(5,1);
    std::cout << "After erase: " << s3 << std::endl;

    // Replace
    s3.replace(6,5,"C++");
    std::cout << "After replace: " << s3 << std::endl;

    // Find
    std::size_t pos = s3.find("C++");
    if(pos != std::string::npos){
        std::cout << "Found C++ at position: " << pos << std::endl;
    }

    // Substring
    std::string sub = s3.substr(0,5);
    std::cout << "Substring: " << sub << std::endl;

    // String to number
    std::string num = "123";
    int x = std::stoi(num);
    std::cout << "String to int: " << x << std::endl;

    // Number to string
    int y = 456;
    std::string str = std::to_string(y);
    std::cout << "Int to string: " << str << std::endl;

    // Iterating string
    std::cout << "Characters: ";
    for(char c : s1){
        std::cout << c << " ";
    }

    std::cout << std::endl;

    return 0;
}