// #include <iostream>
// #include <vector>
// #include <unordered_map>
// #include <string>

// using namespace std;

// class Graphs{
//     private: unordered_map <string, vector<pair<string, int>>>G;
//    public: void addEdge(string u, string v,  int weight ){
//         G[u].push_back({v, weight});
//         G[v].push_back({u, weight});
//     }
    
//     void printGraph() {
//         for (const auto& node : G) {
//             cout << node.first << " -> ";
//             for (const auto& edge : node.second) {
//                 cout << "(" << edge.first << ", " << edge.second << ") ";
//             }
//             cout << endl;
//         }
//     }
// };

// int main() {
//     Graphs graph;
//     graph.addEdge("A", "B", 5);
//     graph.addEdge("A", "C", 3);
//     graph.addEdge("B", "C", 2);
//     graph.addEdge("C", "D", 7);
//     graph.printGraph();
//     return 0;
// }



#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

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

  // Perform BFS (Level Order Traversal)
  
};

int main(){
    Graph G;
    G.addEdge("A", "B", 4);
    G.addEdge("A", "C", 4);
    G.addEdge("B", "C", 2);
    G.addEdge("B", "E", 1);
    G.addEdge("C", "D", 1);
    G.addEdge("D", "F", 1);
    G.addEdge("F", "E", 1);
    G.printGraph();
    return 0;
}

// #include <iostream>
// #include <vector>
// #include <unordered_map>
// #include <string>

// using namespace std;

// class Graphs {
// private:
//     // Adjacency list: node -> (neighbor, weight)
//     unordered_map<string, vector<pair<string, int>>> G;

// public:
//     // Add edge (undirected by default)
//     void addEdge(const string& u, const string& v, int weight, bool directed = false) {
//         G[u].push_back({v, weight});
//         if (!directed) {
//             G[v].push_back({u, weight});
//         }
//     }

//     // Print the weighted graph
//     void printGraph() {
//         for (const auto& node : G) {
//             cout << node.first << " -> ";
//             for (const auto& edge : node.second) {
//                 cout << "(" << edge.first << ", " << edge.second << ") ";
//             }
//             cout << endl;
//         }
//     }
// };

// int main() {
//     Graphs graph;

//     graph.addEdge("A", "B", 5);
//     graph.addEdge("A", "C", 3);
//     graph.addEdge("B", "C", 2);
//     graph.addEdge("C", "D", 7);

//     graph.printGraph();

//     return 0;
// }
