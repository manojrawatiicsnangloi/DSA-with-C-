#include <iostream>
#include <stack>
using namespace std;


class minstack{
    private:
     stack<int> root;
     stack<int> minSt;
     public:
     void push(int value){
        root.push(value);
        if (minSt.empty() || minSt.top() > value){
            minSt.push(value);
        }
     }

     void pop(){
        if (minSt.top() == root.top()){
            minSt.pop();
        }
        root.pop();
     }

    int min(){
        if (!minSt.empty()){
            return minSt.top();
        }
        return -1;
    }
    int top(){
        return root.top();
    }
};

int main(){
    minstack st;
    st.push(5);
    st.push(2);
    st.push(8);
    st.push(1);

    cout << st.min() << endl; // 1
    return 0;
}