# STL Array in C++

## Overview

`std::array` is a container from the **C++ Standard Template Library (STL)** that represents a **fixed-size array**.
It provides the functionality of a normal C-style array along with useful STL methods.

Unlike dynamic containers, the size of `std::array` must be known **at compile time**.

---

## Header File

```cpp
#include <array>
```

---

## Syntax

```cpp
std::array<data_type, size> array_name;
```

Example:

```cpp
std::array<int,5> arr;
```

---

## Example Program

```cpp
#include <iostream>
#include <array>

int main() {

    std::array<int,5> arr = {1,2,3,4,5};

    for(int i = 0; i < arr.size(); i++){
        std::cout << arr[i] << " ";
    }

    return 0;
}
```

Output

```
1 2 3 4 5
```

---

## Important Functions

### size()

Returns the number of elements.

```cpp
arr.size();
```

---

### at()

Access element with bounds checking.

```cpp
arr.at(2);
```

---

### front()

Returns the first element.

```cpp
arr.front();
```

---

### back()

Returns the last element.

```cpp
arr.back();
```

---

### fill()

Fills the entire array with a specific value.

```cpp
arr.fill(10);
```

---

### data()

Returns a pointer to the underlying array.

```cpp
arr.data();
```

---

## Example with STL Functions

```cpp
#include <iostream>
#include <array>

int main(){

    std::array<int,5> arr;

    arr.fill(7);

    std::cout << "First element: " << arr.front() << std::endl;
    std::cout << "Last element: " << arr.back() << std::endl;
    std::cout << "Size: " << arr.size() << std::endl;

}
```

---

## Memory Behavior

* Stored in **stack memory**
* Size cannot change after declaration

Example layout:

```
[1] [2] [3] [4] [5]
```

---

## STL Array vs C-Style Array

| Feature           | C Array | std::array |
| ----------------- | ------- | ---------- |
| Size function     | ❌       | ✅          |
| STL compatibility | ❌       | ✅          |
| Safer access      | ❌       | ✅ (`at()`) |
| Iterator support  | ❌       | ✅          |

---

## STL Array vs Vector

| Feature     | std::array | std::vector     |
| ----------- | ---------- | --------------- |
| Size        | Fixed      | Dynamic         |
| Memory      | Stack      | Heap            |
| Resize      | ❌          | ✅               |
| Performance | Faster     | Slightly slower |

---

## When to Use std::array

Use `std::array` when:

* The number of elements is **known at compile time**
* You need **fast performance**
* You want **STL functions with fixed size**

Example:

```cpp
std::array<int,100> numbers;
```

---

## Topics Covered

1. Introduction to `std::array`
2. Syntax and declaration
3. Accessing elements
4. STL functions (`size`, `at`, `front`, `back`, `fill`)
5. Memory behavior
6. Comparison with C arrays
7. Comparison with `std::vector`
8. Use cases
