#include <iostream>
using namespace std;
#include <queue>

int main(){
    int n;
    cout << "Enter how many integers you want to store";
    cin >> n;
    priority_queue<int> pq;
    for (int i = 1; i <= n; i++){
        cout << "Enter " << i << "st element";
        int x;
        cin >> x;
        pq.push(x);
    }
    while (!pq.empty()){
        cout << pq.top() << ", ";
        pq.pop();
    }
    return 0;
}