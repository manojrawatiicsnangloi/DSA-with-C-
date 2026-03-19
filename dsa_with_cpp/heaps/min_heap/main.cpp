#include <iostream>
#include <vector>
using namespace std;

class MinHeap{
    private : vector<int> root;

    void heapifyUp(int i){
        if (i == 0) return;
        int parent = (i - 1) / 2;
        if (root[parent] > root[i]){
            swap(root[parent], root[i]);
         heapifyUp(parent);
        }
    }

    void heapifyDown(int i){
        int left = i * 2 + 1;
        int right = i * 2 + 2;
        int size = root.size();
        int lowest = i;
        if (left < size && root[lowest] > root[left] ){
            lowest = left;
        }
        if (right < size && root[lowest] > root[right]){
            lowest = right;
        }
        if (lowest != i){
            swap(root[lowest], root[i]);
            heapifyDown(lowest);
        }
    }
public:
    void push(int value){
        root.push_back(value);
     heapifyUp(root.size() - 1);
    }

    void pop(){
        if (root.empty()) return;
        root[0] = root.back();
        root.pop_back();
        if (!root.empty()){
            heapifyDown(0);
        }
    }

    bool isEmpty(){
        return root.empty();
    }
    int top(){
        if (root.empty()) return -1;
        return root.front();
    }
};
int main(){
    MinHeap h;
   vector<int> arr = {4, 5, 1, 3, 2, 10, 9, 8, 11, 20, 15};
   for (int i : arr){
    h.push(i);
   }

       while (!h.isEmpty()) {
        cout << h.top() << " ";
        h.pop();
    }  

    return 0;
}