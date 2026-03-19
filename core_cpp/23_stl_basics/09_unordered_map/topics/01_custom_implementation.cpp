#include <iostream>
#include <vector>

class Node {
    public:
     std::string key;
    std::string value;
    Node * next;
    Node(std::string k, std::string v){
        this -> key = k;
        this -> value = v;
        this -> next = nullptr;
    }
};

class UnorderedMap{
    private:
    std::vector<Node*> bucket;
    int capacity;
    int hash(std::string key) {
   int hashValue = 0;
   for (char c : key) {
       hashValue = hashValue * 31 + c; // better hash
   }
   return hashValue % capacity;
}
    public:UnorderedMap(int size){
        this -> capacity = size;
       bucket.resize(size, nullptr);
    }



    void put(std::string key, std::string value){
        int index = hash(key);
        Node * temp = bucket[index];
        while (temp != nullptr){
            if (temp -> key == key){
                temp -> value = value;
                return;
            }
            temp = temp -> next;
        }
        Node *newNode = new Node(key, value);
        newNode -> next = bucket[index];
        bucket[index] = newNode;
        return;
    }

    std::string get(std::string key){
        int index = hash(key);
        Node * temp = bucket[index];
        while (temp != nullptr){
            if (temp -> key == key){
                return temp -> value;
            }
            temp = temp -> next;
        }
        return "nullptr";
    }
  
};


int main(){

      UnorderedMap mp(10);
    mp.put("name", "Manoj");
    std::cout << mp.get("name") << std::endl;

    return 0;
}