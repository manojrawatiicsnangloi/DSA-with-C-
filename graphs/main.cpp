

#include <iostream>
#include <list>
#include <unordered_map>
#include <string>
using namespace std;

class Graph {
    unordered_map<string, list<string>> adj;

public:
    void addEdge(const string& u, const string& v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void printAdjList() {
        for (auto &pair : adj) {
            cout << pair.first << " : ";
            for (auto &neighbour : pair.second) {
                cout << neighbour << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g;

    g.addEdge("n1", "n2");
    g.addEdge("n2", "n3");
    g.addEdge("n2", "n4");
    g.addEdge("n3", "n4");
    g.addEdge("n3", "n5");

    g.printAdjList();

    return 0;
}


// // Online C++ compiler to run C++ program online
// #include <iostream>
// #include <list>
// using namespace std;

// class Graph{
//     int v;
//     list <int> *l;
//     public:Graph(int v){
//         this -> v = v;
//         l = new list <int> [v];
//     }
//     void addEdge(int u, int v){
//         l[u].push_back(v);
//         l[v].push_back(u);
//     }
//     void printAdjList(){
//         for (int i = 0; i< v; i++){
//             cout << i << " : ";
//             for (int n : l[i]){
//                 cout << n << " ";
//             }
//             cout << endl;
//         }
//     }
// };
// int main() {
//     Graph g(5);
//     g.addEdge(0, 1);
//     g.addEdge(1, 2);
//     g.addEdge(1, 3);
//     g.addEdge(2, 3);
//     g.addEdge(2, 4);
//     g.printAdjList();
//     return 0;
// }
