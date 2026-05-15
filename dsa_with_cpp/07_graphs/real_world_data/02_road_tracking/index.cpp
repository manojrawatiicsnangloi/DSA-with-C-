#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Graph {

private:
    vector<vector<int>> adj;

public:

    Graph(int nodes) {
        adj.resize(nodes);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void printFew(int limit = 10) {

        for (int i = 0; i < limit; i++) {

            cout << i << " -> ";

            for (int neighbor : adj[i]) {
                cout << neighbor << " ";
            }

            cout << "\n";
        }
    }
};

int main() {

    // total nodes from dataset
    Graph graph(1965206);

    ifstream file("road.txt");

    if (!file.is_open()) {
        cout << "File not found\n";
        // return 0;
    }

    string line;

    while (getline(file, line)) {

        // skip comments
    if (line.empty() || line[0] == '#') continue;

        int u, v;

        stringstream ss(line);

        ss >> u >> v;

        graph.addEdge(u, v);
    }

    file.close();

    cout << "Graph Loaded Successfully\n\n";

    graph.printFew();

    return 0;
}