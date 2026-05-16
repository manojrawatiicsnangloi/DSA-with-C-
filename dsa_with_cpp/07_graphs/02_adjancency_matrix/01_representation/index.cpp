#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Graph {

private:
    vector<vector<int>> matrix;

    unordered_map<string, int> indexMap;

    vector<string> nodes;

public:

    Graph() {

        nodes = {"A","B","C","D","E","F","G"};

        for (int i = 0; i < nodes.size(); i++) {
            indexMap[nodes[i]] = i;
        }

        matrix.resize(7, vector<int>(7, 0));
    }

    void addEdge(string u, string v) {

        int i = indexMap[u];
        int j = indexMap[v];

        matrix[i][j] = 1;
        matrix[j][i] = 1;
    }

    void printMatrix() {

        cout << "  ";

        for (string node : nodes)
            cout << node << " ";

        cout << "\n";

        for (int i = 0; i < matrix.size(); i++) {

            cout << nodes[i] << " ";

            for (int j = 0; j < matrix[i].size(); j++) {

                cout << matrix[i][j] << " ";
            }

            cout << "\n";
        }
    }
};

int main() {

    Graph gp;

    gp.addEdge("A","D");
    gp.addEdge("A","E");
    gp.addEdge("A","C");
    gp.addEdge("E","C");
    gp.addEdge("C","B");
    gp.addEdge("C","F");
    gp.addEdge("C","G");
    gp.addEdge("B","F");
    gp.addEdge("G","F");

    gp.printMatrix();

    return 0;
}