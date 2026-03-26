#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class graphs {
private:
    unordered_map<string, int> index;   // vertex → index
    vector<string> vertices;            // index → vertex
    vector<vector<int>> matrix;         // adjacency matrix

public:
    void add(const string &u, const string &v, const int &w) {
        // assign index if not present
        if (index.find(u) == index.end()) {
            index[u] = vertices.size();
            vertices.push_back(u);
        }
        if (index.find(v) == index.end()) {
            index[v] = vertices.size();
            vertices.push_back(v);
        }

        int n = vertices.size();
        // resize matrix if needed
        matrix.resize(n);
        for (int i = 0; i < n; i++) {
            matrix[i].resize(n, 0);
        }

        // add edge
        matrix[index[u]][index[v]] = w;
    }

    void printMatrix() {
        cout << "Adjacency Matrix:\n  ";
        for (auto &v : vertices) cout << v << " ";
        cout << "\n";

        for (int i = 0; i < vertices.size(); i++) {
            cout << vertices[i] << " ";
            for (int j = 0; j < vertices.size(); j++) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    graphs gp;

    gp.add("D","A", 4);
    gp.add("A","E", 4);
    gp.add("D","E", 2);
    gp.add("A","C", 3);
    gp.add("E","C", 4);
    gp.add("C","B", 3);
    gp.add("C","F", 4);
    gp.add("G","C", 5);
    gp.add("F","B", 2);
    gp.add("G","F", 5);

    gp.printMatrix();

    return 0;
}