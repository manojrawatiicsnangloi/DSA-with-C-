#include <iostream>
#include <vector>

using namespace std;

class MatrixGraph {

private:

    // Adjacency Matrix
    vector<vector<int>> matrix;

    // Node names
    vector<string> nodes;

public:

    // Constructor
    MatrixGraph(vector<string> nodeNames) {

        nodes = nodeNames;

        int n = nodes.size();

        matrix.resize(n, vector<int>(n, 0));
    }

    // Find index of node
    int getIndex(string node) {

        for(int i = 0; i < nodes.size(); i++) {

            if(nodes[i] == node)
                return i;
        }

        return -1;
    }

    // Add Edge
    void addEdge(string u, string v) {

        int i = getIndex(u);
        int j = getIndex(v);

        if(i == -1 || j == -1) {
            cout << "Invalid Node\n";
            return;
        }

        matrix[i][j] = 1;
        matrix[j][i] = 1;
    }

    // Print Matrix
    void printMatrix() {

        cout << "  ";

        for(string node : nodes)
            cout << node << " ";

        cout << "\n";

        for(int i = 0; i < matrix.size(); i++) {

            cout << nodes[i] << " ";

            for(int j = 0; j < matrix[i].size(); j++) {

                cout << matrix[i][j] << " ";
            }

            cout << "\n";
        }
    }
};

int main() {

    vector<string> nodes = {
        "A","B","C","D"
    };

    MatrixGraph gp(nodes);

    gp.addEdge("A","B");
    gp.addEdge("A","C");
    gp.addEdge("B","D");

    gp.printMatrix();

    return 0;
}