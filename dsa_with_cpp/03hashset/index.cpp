#include <iostream>
#include <vector>

class HashSet {
private:
    std::vector<int> table;

public:
void insert(int value){
    table.push_back(value);
}
bool contains(int value){
    for(int item : table){
        if(item == value){
            return true;
        }
    }
    return false;
}
void remove(int value){
    for(auto it = table.begin(); it != table.end(); it++){
        if(*it == value){
            table.erase(it);
            return;
        }
    }
}

void display(){
    for(int item : table){
        std::cout << item << " ";
    }
    std::cout << std::endl;
}
};
int main(){
    HashSet set;

    set.insert(10);
    set.insert(20);
    set.insert(30);

    set.display();

    std::cout << set.contains(20) << std::endl;
    std::cout << set.contains(50) << std::endl;

    set.remove(20);

    set.display();

    return 0;
}