// #include <iostream>
// using namespace std;


// class Node {
//     public :
//      string key;
//      string value;
//      Node * next;
//     Node (string k, string v){
//         this -> key = k;
//         this -> value = v;
//         this -> next = nullptr;
//     }
// };


// class custom_hashmap {
//     private:
//   static const int bucket_size = 10;  
//    Node* buckets[bucket_size];
   
//     public: custom_hashmap(){
//         for (int i = 0; i < bucket_size; i++){
//           buckets[i] = nullptr; 
//         }  
//     }  

//     int hashFunction(string key){
//         int sum = 0;
//         for (char ch : key){
//             sum += ch;
//         }
//         return sum % bucket_size; 
//     }

//     void put(string k, string v){
//         int index = hashFunction(k);
//         Node * head = buckets[index];
//         while (head != nullptr){
//             if (head -> key == k){
//                 head -> value = v;
//                 cout << "Value Updated Successfully";
//                 return;
//             }
//             head = head -> next;
//         }
//         Node * newNode = new Node(k, v);
//         newNode -> next = buckets[index];
//         buckets[index] = newNode; 
//     }

//     string get(string k){
//         int  index = hashFunction(k);
//         Node * head = buckets[index];
//         while (head != nullptr){
//             if (head -> key == k){
//                 return head -> value;
//             }
//             head = head -> next; 
//         }
//         return "nullptr";
//     }
// };

// int main(){

//     custom_hashmap data;
//     data.put("name", "abc");
//     data.put("email", "abc@gmail.com");
//     cout << data.get("name") << "\n";
//     cout << data.get("email") << "\n";
//     cout << data.get("city") << "\n";

//     return 0;
// }


#include <iostream>
using namespace std;

// Node to store key-value pair
class Node {
public:
    string key;
    string value;
    Node* next;

    Node(string k, string v) {
        key = k;
        value = v;
        next = nullptr;
    }
};

class MyHashMap {
private:
    static const int SIZE = 10;  // Bucket size
    Node* buckets[SIZE];

public:
    MyHashMap() {
        for (int i = 0; i < SIZE; i++) {
            buckets[i] = nullptr;
        }
    }

    //  Hash function
    int hashFunction(string key) {
        int sum = 0;
        for (char ch : key) {
            sum += ch;
        }
        return sum % SIZE;
    }

    //  put() → insert or update
    void put(string key, string value) {
        int index = hashFunction(key);
        Node* newNode = new Node(key, value);
        Node* head = buckets[index];

        // Check if key already exists → update it
        while (head != nullptr) {
            if (head->key == key) {
                head->value = value;
                cout << "Updated: " << key << " \n";
                return;
            }
            head = head->next;
        }

        // Insert at beginning of chain
        newNode->next = buckets[index];
        buckets[index] = newNode;
        cout << "Inserted: " << key << " \n";
    }

    //  get() → fetch value by key
    string get(string key) {
        int index = hashFunction(key);
        Node* head = buckets[index];

        while (head != nullptr) {
            if (head->key == key) {
                return head->value;
            }
            head = head->next;
        }
        return "Key Not Found";
    }

    //  remove() → delete key
    void remove(string key) {
        int index = hashFunction(key);
        Node* head = buckets[index];
        Node* prev = nullptr;

        while (head != nullptr) {
            if (head->key == key) {
                if (prev == nullptr) {
                    buckets[index] = head->next;
                } else {
                    prev->next = head->next;
                }
                delete head;
                cout << "Removed: " << key << "\n";
                return;
            }
            prev = head;
            head = head->next;
        }

        cout << "Key Not Found Cannot remove\n";
    }

    //  Display HashMap
    void display() {
        cout << "\n--- HASHMAP CONTENT ---\n";
        for (int i = 0; i < SIZE; i++) {
            cout << "Bucket " << i << ": ";
            Node* head = buckets[i];
            while (head != nullptr) {
                cout << "[" << head->key << " : " << head->value << "] -> ";
                head = head->next;
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    MyHashMap map;

    map.put("name", "Manoj");
    map.put("email", "manoj@gmail.com");
    map.put("city", "Delhi");
    map.put("password", "Manoj@123");
    map.put("img", "pic.png");
    map.put("hobby", "Exercise");
    map.put("profession", "Coder");

    cout << "\nGet email: " << map.get("email") << endl;
    cout << "Get age: " << map.get("age") << endl;
    map.display();

    map.remove("city");
    map.remove("country");

    map.display();
    return 0;
}
