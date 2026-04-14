#include <iostream>

class priority_queue {
    int* arr;
    int cap;
    int size;

public:
    // constructor
    priority_queue(int c) {
        cap = c;
        size = 0;
        arr = new int[c];
    }

    // insertion
    void push(int value){
        if (size == cap){ return;}
        arr[size] = value;
        heapifyUp(size);
        size++;
    };      // insert element (heapify up)

    // deletion
    void pop(){
        if (size == 0) return;
        arr[0] = arr[size - 1];
        size--;
        heapifyDown(0);
    };                // remove highest priority (root)

    // access
    int top(){
        if (isEmpty()) return -1;
        return arr[0];
    };                 // get max element

    // utility
    bool isEmpty(){
        return size == 0; 
    };
    bool isFull(){
        return size == cap;
    };
    int getSize(){
        return size;
    };

   

    // heapify functions
    void heapifyUp(int i){
        if (i == 0) return;
        int parent = (i - 1)/2;
        if (arr[i] < arr[parent]){
            std::swap(arr[i], arr[parent]);
            heapifyUp(parent);
        }
    };
    void heapifyDown(int i){
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int min = i;
        if ( (left < size) && arr[left]< arr[min] ){
            min = left;
        }
        
        if (right < size && arr[right]< arr[min] ){
            min = right;
        }

        if (min != i){
            std::swap(arr[min], arr[i]);
            heapifyDown(min);
        }

    };

    // debug / display
    void display(){
        for (int i = 0; i < size; i++){
            std::cout << arr[i] << " ";
        }
    };
};

int main() {
    priority_queue pq(10);
    pq.push(10);
    pq.push(20);
    pq.push(40);
    pq.push(98);
    pq.push(24);
    pq.push(21);
    pq.push(43);
    pq.push(78);
    pq.push(67);
    pq.push(54);
    pq.push(4);
    pq.push(5);
    std::cout << pq.top() << "\n";
    pq.pop();
    pq.display();
    return 0;
}