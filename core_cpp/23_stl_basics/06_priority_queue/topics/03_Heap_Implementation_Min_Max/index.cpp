#include <iostream>
#include <vector>
using namespace std;


class priority_queue{
    private : vector<int> root;
    void heapifyUp(int i){
        if (i < 0)
            return;
        int p = i / 2 - 1;
        if (root[p] > i){
            swap(root[p], root[i]);
            heapifyUp(p);
        }
    }
    public:
    void push(int value){
        root.push_back(value);
        heapifyUp(root.size() - 1);
    }


    void pop(){
        if(isEmpty()) return;
        int back = root.back();
        root[0] = back;
        root.pop_back();
    }

    bool isEmpty(){
        return root.empty();
    }
    int top(){
        if (isEmpty()) return -1;
        return root[0];
    }
};

int main(){

    priority_queue pq;
      pq.push(34);
    pq.push(43);
    pq.push(78);
    pq.push(98);
    pq.push(1);

    while (!pq.isEmpty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << "Top: " << pq.top() << endl;  // 1

    pq.pop();
    cout << "Top after pop: " << pq.top() << endl;
    return 0;
}