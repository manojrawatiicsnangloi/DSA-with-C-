#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

struct Node {
    string name;
    int g; // cost from start
    int f; // g + h

    bool operator>(const Node &other) const {
        return f > other.f;
    }
};

class Graph {
private:
    unordered_map<string, vector<pair<string, int>>> adj;

public:
    void add(string u, string v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    void aStar(string start,
               string goal,
               unordered_map<string, int> heuristic) {

        priority_queue<Node, vector<Node>, greater<Node>> pq;

        unordered_map<string, int> gCost;
        unordered_map<string, string> parent;

        // initialize
        for (auto &p : adj) {
            gCost[p.first] = INT_MAX;
        }

        gCost[start] = 0;

        pq.push({start, 0, heuristic[start]});

        while (!pq.empty()) {

            Node current = pq.top();
            pq.pop();

            string u = current.name;

            if (u == goal) break;

            for (auto &edge : adj[u]) {

                string v = edge.first;
                int weight = edge.second;

                int newG = gCost[u] + weight;

                if (newG < gCost[v]) {
                    gCost[v] = newG;
                    parent[v] = u;

                    int f = newG + heuristic[v];

                    pq.push({v, newG, f});
                }
            }
        }

        // Reconstruct path
        vector<string> path;
        string cur = goal;

        if (parent.find(cur) == parent.end() && cur != start) {
            cout << "No path found\n";
            return;
        }

        path.push_back(cur);

        while (parent.find(cur) != parent.end()) {
            cur = parent[cur];
            path.push_back(cur);
        }

        reverse(path.begin(), path.end());

        cout << "Path: ";
        for (auto &node : path) {
            cout << node << " ";
        }
        cout << endl;
    }
};

int main() {

    Graph gp;

    gp.add("D", "A", 4);
    gp.add("A", "E", 4);
    gp.add("D", "E", 2);
    gp.add("A", "C", 3);
    gp.add("E", "C", 4);
    gp.add("C", "B", 3);
    gp.add("C", "F", 4);
    gp.add("G", "C", 5);
    gp.add("F", "B", 2);
    gp.add("G", "F", 5);

    unordered_map<string, int> heuristic = {
        {"A", 7},
        {"B", 2},
        {"C", 4},
        {"D", 6},
        {"E", 3},
        {"F", 2},
        {"G", 0}
    };

    gp.aStar("A", "E", heuristic);

    return 0;
}