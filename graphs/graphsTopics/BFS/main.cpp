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
        unordered_map <string, bool>visited;
        queue<string> q;
        visited[start] = true;
        q.push(start);
        cout << "starting from node : " <<start << " \n ";
        while(!q.empty()){
            string node = q.front();
            cout << node << " ";
            q.pop();
            for (const auto & n : G[node]){
                if (!visited[n.first]){
                    visited[n.first]  = true;
                    q.push(n.first);
                }
            }
        }
    }
};

int main() {
    Graph G;

    // Adding edges to the graph
    G.addEdge("A", "B", 4);
    G.addEdge("A", "C", 4);
    G.addEdge("B", "C", 2);
    G.addEdge("B", "E", 1);
    G.addEdge("C", "D", 1);
    G.addEdge("D", "F", 1);
    G.addEdge("F", "E", 1);

    // Print the graph
    G.printGraph();

    // Perform BFS starting from node "A"
    G.BFS("A");

    return 0;
}
