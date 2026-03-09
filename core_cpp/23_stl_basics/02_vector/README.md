# C++ STL — Vector

## Overview

`std::vector` is a dynamic array provided by the C++ Standard Library.
Unlike normal arrays, vectors can **grow or shrink automatically**. They store elements in **contiguous memory**, which allows fast access using indexes.

Header file used:

```cpp
#include <vector>
```

---

# Creating Vectors

```cpp
std::vector<int> v1;              // empty vector
std::vector<int> v2 = {1,2,3,4};  // initializer list
std::vector<int> v3(5);           // vector of size 5
std::vector<int> v4(5,10);        // 5 elements with value 10
```

---

# Adding Elements

## push_back()

Adds an element to the end of the vector.

```cpp
v.push_back(10);
v.push_back(20);
```

Example:

```cpp
std::vector<int> v;

v.push_back(5);
v.push_back(15);
v.push_back(25);
```

Result:

```
5 15 25
```

---

# Accessing Elements

### Using Index

```cpp
v[i]
```

Example:

```cpp
std::cout << v[0];
```

### Using `.at()`

```cpp
v.at(i)
```

Difference:

* `[]` → no bounds checking
* `at()` → throws exception if out of range

---

# Important Vector Properties

### size()

Returns number of elements.

```cpp
v.size();
```

### capacity()

Returns allocated storage.

```cpp
v.capacity();
```

### empty()

Checks if vector is empty.

```cpp
v.empty();
```

---

# Modifying Vectors

## insert()

Insert element at specific position.

```cpp
v.insert(v.begin()+1, 100);
```

Example:

```
Before: 10 20 30
After : 10 100 20 30
```

---

## erase()

Removes element.

```cpp
v.erase(v.begin()+2);
```

Example:

```
Before: 10 20 30 40
After : 10 20 40
```

---

## pop_back()

Removes last element.

```cpp
v.pop_back();
```

---

## clear()

Removes all elements.

```cpp
v.clear();
```

---

# Iterating Through Vector

### Range-based loop

```cpp
for(int x : v){
    std::cout << x;
}
```

---

### Using Iterators

```cpp
for(auto it = v.begin(); it != v.end(); it++){
    std::cout << *it;
}
```

---

# Example Program

```cpp
#include <iostream>
#include <vector>

int main(){

    std::vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    for(int x : v){
        std::cout << x << " ";
    }

    std::cout << "\nSize: " << v.size();

    return 0;
}
```

Output:

```
10 20 30
Size: 3
```

---

# Advantages of Vector

* Dynamic resizing
* Fast random access (`O(1)`)
* Automatic memory management
* Compatible with STL algorithms

---

# What I Learned

* Creating vectors
* Adding elements with `push_back`
* Accessing elements with `[]` and `at()`
* Using `size`, `capacity`, and `empty`
* Inserting and removing elements
* Iterating using loops and iterators
