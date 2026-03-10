#include <iostream>

class stack{
    private: int top;
    int size;
    int *arr;
    public : stack(int s){
        this -> size = s;
        arr = new int[s];
        top = -1;
    }
    bool isFull(){
        return this -> size - 1 == top; 
    }
    bool isEmpty() {
        return top == -1;
    }
    void push(int value){
        if (isFull()){
            std::cout<< "Stack overflow";
            return;
        }
        arr[++top] = value;
    }
    int peek(){
        if (isEmpty()){
            std::cout << "Stack is empty";
        }
        return arr[top];
    }
    void display(){
        for (int i = top; i >= 0; i--){
            std::cout << arr[i] << " ";
        }
        std::cout<< std::endl;
    }
    void pop(){
        if (top == -1){
            std::cout << "Stack is empty";
        }
        top--;
    }
};
int main(){                                                                    
    stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.display();
       s.pop();
    s.display();

    std::cout << "Top Element: " << s.peek() << std::endl;
    return 0;

}