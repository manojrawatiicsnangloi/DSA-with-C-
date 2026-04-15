#include <iostream>

class stack{
    private: int * root;
    int capacity;
    int top;
    int size;
    public:stack(int cp){
        root = new int[capacity];
        capacity = cp;
        top = -1;
    }
    void push(int value){
        if (top  == capacity - 1) return;
        root[++top] = value;    
        
    }
    void pop(){
        if (top == -1){
            return;
        }
        top--;
    }


    void printStack(){
        for (int i = 0; i <= top; i++){
            std::cout << root[i] << " "; 
        }
    }
};


int main(){
    return 0;
}