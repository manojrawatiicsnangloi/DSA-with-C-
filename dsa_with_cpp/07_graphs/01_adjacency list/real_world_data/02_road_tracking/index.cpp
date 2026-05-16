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
    ifstream file("road.txt");
    if (!file.is_open()) {
        cout << "File not found\n";
        return 0;
    }
    string line;
    int maxNode = -1;
    // PASS 1 -> find maximum node id
    while (getline(file, line)) {
        if (line.empty() || line[0] == '#')
            continue;
        int u, v;
        stringstream ss(line);

        if (!(ss >> u >> v))
            continue;

        maxNode = max(maxNode, max(u, v));
    }

    cout << "Max Node ID: " << maxNode << "\n";

    // create graph
    Graph graph(maxNode + 1);

    // reset file pointer
    file.clear();
    file.seekg(0);

    // PASS 2 -> load graph
    while (getline(file, line)) {

        if (line.empty() || line[0] == '#')
            continue;

        int u, v;

        stringstream ss(line);

        if (!(ss >> u >> v))
            continue;

        graph.addEdge(u, v);
    }

    file.close();

    cout << "Graph Loaded Successfully\n\n";

    graph.printFew();

    return 0;
}