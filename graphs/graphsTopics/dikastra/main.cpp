#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
#include <climits>
#include <queue>
#include <functional>

class Graph{
    private : unordered_map <string, vector<pair<string, int>>> G;
    public : void addEdge(string v, string u, int w){
        G[v].push_back({u, w});
        G[u].push_back({v, w});
    }

      void printGraph() const {
        // Check if the graph is empty
        if (G.empty()) {
            cout << "The graph is empty.\n";
            return;
        }

        // Loop through each vertex and its adjacent vertices
        for (const auto& i : G) {
            cout << i.first << " : ";
            for (const auto& j : i.second) {
                cout << "(" << j.first << ", " << j.second << ") "; // Format: (neighbor, weight)
            }
            cout << "\n";
        }
    }

    void dijkstra(string src) {
        unordered_map<string, int> dist;

        for (auto &i : G)
            dist[i.first] = INT_MAX;

        dist[src] = 0;

        priority_queue<
            pair<int, string>,
            vector<pair<int, string>>,
            greater<pair<int, string>>
        > pq;

        pq.push({0, src});

        while (!pq.empty()) {
            pair<int, string> top = pq.top();  // ✅ FIX
            pq.pop();

            int currDist = top.first;
            string node = top.second;

            if (currDist > dist[node]) continue;

            for (auto &nbr : G[node]) {
                string next = nbr.first;
                int weight = nbr.second;

                if (dist[node] + weight < dist[next]) {
                    dist[next] = dist[node] + weight;
                    pq.push({dist[next], next});
                }
            }
        }

        cout << "\nDijkstra from " << src << ":\n";
        for (auto &i : dist) {
            cout << src << " -> " << i.first << " = " << i.second << "\n";
        }
    }

  // Perform BFS (Level Order Traversal)
  
};

int main(){
    Graph G;
    G.addEdge("A", "D", 4);
    G.addEdge("A", "E", 4);
    G.addEdge("A", "C", 3);
    G.addEdge("D", "E", 2);
    G.addEdge("E", "C", 4);
    G.addEdge("E", "G", 5);
    G.addEdge("C", "B", 2);
    G.addEdge("C", "F", 5);
    G.addEdge("C", "G", 5);
    G.addEdge("B", "F", 2);
    G.addEdge("F", "G", 5);
    G.printGraph();
    G.dijkstra("D");
    return 0;
}
