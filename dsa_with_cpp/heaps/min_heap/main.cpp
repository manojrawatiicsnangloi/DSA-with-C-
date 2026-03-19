#include <iostream>
#include <vector>
using namespace std;

class MinHeap{
    private : vector<int> root;

    void heapfyUp(int i){
        if (i == 0) return;
        int parent = i - 1 / 2;
        if (root[parent] > root[i]){
            swap(root[parent], root[i]);
            heapfyUp(parent);
        }
    }

    void heapifyDown(int i){
        
    }
    void heapfyDown(){}
    void push(){

    }
};
int main(){

    return 0;
}