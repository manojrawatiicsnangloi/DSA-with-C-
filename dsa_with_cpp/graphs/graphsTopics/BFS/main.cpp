#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue> // To use the queue for BFS
using namespace std;

class Graph {
private:
    unordered_map<string, vector<pair<string, int>>> G; // Adjacency list for weighted graph

public:
    // Add an edge between vertex v and u with weight w
    void addEdge(const string& v, const string& u, int w) {
        G[v].push_back({u, w});
        G[u].push_back({v, w}); // Since it's an undirected graph
    }

    // Print the graph's adjacency list
    void printGraph() const {
        if (G.empty()) {
            cout << "The graph is empty.\n";
            return;
        }

        for (const auto& i : G) {
            cout << i.first << " : ";
            for (const auto& j : i.second) {
                cout << "(" << j.first << ", " << j.second << ") "; // Format: (neighbor, weight)
            }
            cout << "\n";
        }
    }

   void BFS(string start){
        unordered_map <string, bool> v;
        queue <string> q;
        q.push(start);
        v[start] = true;
        while (!q.empty()){
            string node = q.front();
            cout << node << " ";
            q.pop();
            for (auto &i: G[node]){
                if(!v[i.first]){
                    q.push(i.first);
                    v[i.first] = true;
                }
            }
        }
   }

   void DFSHelper(string node, unordered_map <string, bool> &v){
    v[node] = true;
    cout << node << " ";
    for (auto &i:G[node]){
        if (!v[i.first]){
            DFSHelper(i.first, v);
        }
    } 
   }

   void DFS(const string& start) {

    cout << " DFS ";
    unordered_map<string, bool> visited;
    DFSHelper(start, visited);
}

};
int main() {
    Graph G;

    // A wider + deeper graph (better for BFS vs DFS)
    G.addEdge("A", "B", 2);
    G.addEdge("A", "C", 4);
    G.addEdge("A", "D", 3);

    G.addEdge("B", "E", 9);
    G.addEdge("B", "F", 6);

    G.addEdge("F", "H", 7);

    G.addEdge("D", "G", 9);

    // Print the graph
    G.printGraph();

    cout << "BFS  ";
    G.BFS("A");

    cout << "\nDFS  ";
    G.DFS("A");

    return 0;
}
