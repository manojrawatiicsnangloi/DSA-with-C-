# C++ STL — Strings

## Overview

`std::string` is part of the C++ Standard Library and represents a dynamic sequence of characters.
Unlike C-style character arrays, `std::string` automatically manages memory and provides many useful functions for string manipulation.

Header file used:

```cpp
#include <string>
```

---

# Creating Strings

```cpp
std::string s1 = "Hello";
std::string s2("World");
std::string s3(5, 'A'); // AAAAA
```

---

# Common String Operations

## Length / Size

Returns the number of characters in the string.

```cpp
s.length();
s.size();
```

Example:

```cpp
std::string s = "Hello";
std::cout << s.length(); // 5
```

---

## Access Characters

```cpp
s[i]
s.at(i)
```

Example:

```cpp
std::string s = "Hello";
std::cout << s[0]; // H
```

Difference:

* `[]` does not check bounds
* `.at()` checks bounds and throws an exception

---

# Modifying Strings

## Append

```cpp
s.append(" World");
```

or

```cpp
s += " World";
```

---

## Insert

```cpp
s.insert(position, "text");
```

Example:

```cpp
std::string s = "Hello";
s.insert(5, " World");
```

---

## Erase

```cpp
s.erase(start_index, length);
```

Example:

```cpp
std::string s = "Hello World";
s.erase(5,1); // removes space
```

---

## Replace

```cpp
s.replace(start, length, "new_text");
```

Example:

```cpp
std::string s = "Hello World";
s.replace(6,5,"C++");
```

---

# Searching in Strings

## Find

```cpp
s.find("text");
```

Example:

```cpp
std::string s = "Hello World";
std::cout << s.find("World");
```

Returns:

* position of first match
* `std::string::npos` if not found

---

# Substring

```cpp
s.substr(start, length);
```

Example:

```cpp
std::string s = "Hello World";
std::string sub = s.substr(6,5); // World
```

---

# Comparing Strings

```cpp
if(s1 == s2)
```

Other comparison operators:

```
==
!=
<
>
<=
>=
```

Comparison is **lexicographical (dictionary order)**.

---

# Converting String to Number

```cpp
stoi()   // string to int
stol()   // string to long
stod()   // string to double
```

Example:

```cpp
std::string s = "123";
int x = stoi(s);
```

---

# Converting Number to String

```cpp
to_string()
```

Example:

```cpp
int x = 10;
std::string s = std::to_string(x);
```

---

# Iterating Through a String

Using loop:

```cpp
for(char c : s){
    std::cout << c;
}
```

Using iterator:

```cpp
for(auto it = s.begin(); it != s.end(); it++){
    std::cout << *it;
}
```

---

# Important Functions Summary

| Function    | Purpose               |
| ----------- | --------------------- |
| `size()`    | Returns string length |
| `append()`  | Adds text at end      |
| `insert()`  | Inserts text          |
| `erase()`   | Removes characters    |
| `replace()` | Replaces text         |
| `find()`    | Searches substring    |
| `substr()`  | Extracts substring    |

---

# Example Program

```cpp
#include <iostream>
#include <string>

int main(){
    std::string s = "Hello";

    s += " World";

    std::cout << s << std::endl;
    std::cout << s.length() << std::endl;
    std::cout << s.substr(6,5) << std::endl;

    return 0;
}
```

Output:

```
Hello World
11
World
```

---

# What I Learned

* How to create `std::string`
* String modification operations
* Searching inside strings
* Extracting substrings
* Converting between strings and numbers
* Iterating over strings
