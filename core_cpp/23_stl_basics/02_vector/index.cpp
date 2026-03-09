#include <iostream>
#include <vector>

int main() {

    // Creating vectors
    std::vector<int> v1;                // empty vector
    std::vector<int> v2 = {1,2,3,4,5};  // initializer list
    std::vector<int> v3(5,10);          // 5 elements with value 10

    // Adding elements
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);

    std::cout << "Vector v1 elements: ";
    for(int x : v1){
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // Access elements
    std::cout << "First element: " << v1[0] << std::endl;
    std::cout << "Using at(): " << v1.at(1) << std::endl;

    // Size and capacity
    std::cout << "Size: " << v1.size() << std::endl;
    std::cout << "Capacity: " << v1.capacity() << std::endl;

    // Insert element
    v1.insert(v1.begin()+1, 15);

    std::cout << "After insert: ";
    for(int x : v1){
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // Erase element
    v1.erase(v1.begin()+2);

    std::cout << "After erase: ";
    for(int x : v1){
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // Pop last element
    v1.pop_back();

    std::cout << "After pop_back: ";
    for(int x : v1){
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // Check if empty
    if(v1.empty()){
        std::cout << "Vector is empty" << std::endl;
    }else{
        std::cout << "Vector is not empty" << std::endl;
    }

    // Clear vector
    v1.clear();
    std::cout << "Size after clear: " << v1.size() << std::endl;

    return 0;
}