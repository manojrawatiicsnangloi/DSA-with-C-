#include <iostream>
#include <stack>

int main() {

    std::stack<int> st;

    // push elements
    st.push(10);
    st.push(20);
    st.push(30);

    // top element
    std::cout << "Top element: " << st.top() << std::endl;

    // size
    std::cout << "Stack size: " << st.size() << std::endl;

    // pop element
    st.pop();

    std::cout << "After pop, top element: " << st.top() << std::endl;

    // check empty
    if(st.empty()){
        std::cout << "Stack is empty" << std::endl;
    } else {
        std::cout << "Stack is not empty" << std::endl;
    }

    // printing stack (copy required)
    std::stack<int> temp = st;

    std::cout << "Stack elements: ";
    while(!temp.empty()){
        std::cout << temp.top() << " ";
        temp.pop();
    }

    return 0;
}