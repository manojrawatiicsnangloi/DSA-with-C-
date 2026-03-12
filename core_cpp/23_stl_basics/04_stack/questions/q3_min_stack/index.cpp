#include <iostream>
#include <stack>

class MinStack
{
private:
    std::stack<int> main_stack;
    std::stack<int> min_stack;

public:
    void push(int value)
    {
        main_stack.push(value);
        if (min_stack.empty() || value < min_stack.top())
        {
            min_stack.push(value);
        }
    }
    void pop()
    {
        if (main_stack.empty())
        {
            return;
        }
        int removed = main_stack.top();
        main_stack.pop();
        if (removed == min_stack.top())
        {
            min_stack.pop();
        }
    }

    int top()
    {
        if (main_stack.empty())
        {
            return -1;
        }

        return main_stack.top();
    }
    int getMin()
    {
        if (min_stack.empty())
        {
            return -1;
        }
        return min_stack.top();
    }
};

int main()
{
    MinStack s;
    s.push(5);
    s.push(3);
    s.push(7);
    s.push(2);
    std::cout << "Minimum: " << s.getMin() << std::endl;
    s.pop();
    std::cout << "Minimum after pop: " << s.getMin() << std::endl;
    return 0;
}