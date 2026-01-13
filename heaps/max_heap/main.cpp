#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
private:
    vector<int> heap;

    // Restore heap property upwards (recursive)
    void heapifyUp(int i) {
        if (i == 0) return;

        int parent = (i - 1) / 2;

        if (heap[parent] <= heap[i]) return;

        swap(heap[parent], heap[i]);
        heapifyUp(parent);
    }

    // Restore heap property downwards (recursive)
    void heapifyDown(int i) {
        int n = heap.size();
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < n && heap[left] < heap[smallest])
            smallest = left;

        if (right < n && heap[right] < heap[smallest])
            smallest = right;

        // Base case: heap property satisfied
        if (smallest == i) return;

        swap(heap[i], heap[smallest]);
        heapifyDown(smallest);
    }

public:
    // Insert element
    void push(int x) {
        heap.push_back(x);
        heapifyUp(heap.size() - 1);
    }

    // Remove minimum element
    void pop() {
        if (heap.empty()) return;

        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty())
            heapifyDown(0);
    }

    // Get minimum element
    int top() const {
        if (heap.empty())
            throw runtime_error("Heap is empty");
        return heap[0];
    }

    bool empty() const {
        return heap.empty();
    }

    int size() const {
        return heap.size();
    }

    // Debug helper
    void print() const {
        for (int x : heap)
            cout << x << " ";
        cout << endl;
    }
    // Build heap from an entire array (O(n))
    void buildFromArray(const vector<int>& arr) {
    heap = arr;  // copy array

    // start from last non-leaf node
    for (int i = heap.size() / 2 - 1; i >= 0; i--) {
        heapifyDown(i);
    }
}

};

int main() {
    MinHeap h;

    vector<int> arr = {4, 5, 1, 3, 2, 10, 9, 8, 11, 20, 15};

    h.buildFromArray(arr);
    h.print();   // min heap structure

    while (!h.empty()) {
        cout << h.top() << " ";
        h.pop();
    }  // Heap structure (not sorted)

}
