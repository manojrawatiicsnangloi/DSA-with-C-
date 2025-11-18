#include <iostream>
#include <queue>  // Include STL queue
using namespace std;

int main() {
    queue<int> q;

    // Enqueue elements
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    cout << "Front element: " << q.front() << endl;
    cout << "Rear element: " << q.back() << endl;

    // Dequeue one element
    q.pop();  // Removes 10

    // Traverse queue (destructively)
    cout << "Elements in queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
