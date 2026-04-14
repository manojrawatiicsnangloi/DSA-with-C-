#include <iostream>
#include <stack>

class queue {
    std::stack<int> s1;  // input stack
    std::stack<int> s2;  // output stack

public:
    // constructor
    queue() {}

    // insertion (enqueue)
    void push(int value){
        s1.push(value);
    };   // add element

    // deletion (dequeue)
    void pop() {
        move();
        if (!s2.empty()){
            s2.pop();
        }
    };             // remove front element
    void move(){
        if (s2.empty()){
            while (!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
    }


    // access
    int front(){
        move();
        if (!s2.empty()){
            return s2.top();
        }
        return -1;
    };            // get front element

    // utility
    bool isEmpty(){
        return s1.empty() && s2.empty();
    };
    int size(){
        return s1.size() + s2.size();
    };

    // debug
    void display(){
        std::stack<int> temp1 = s1;
        std::stack<int> temp2 = s2;
        while (!temp2.empty()){
            std::cout << temp2.top() << " ";
            temp2.pop();
        }

        std::stack<int> rev;
            while (!temp1.empty()){
            rev.push(temp1.top()) ;
            temp1.pop();
        }

        while (!rev.empty()){
            std::cout << rev.top() << " ";
            rev.pop();
        }
    };
};

int main() {
    queue q;

    q.push(10);
    q.push(20);
    q.push(30);

    std::cout << q.front() << "\n";

    q.pop();

    q.display();

    return 0;
}