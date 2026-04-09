#include <iostream>
#include <unordered_map>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

class graphs
{
private:
    unordered_map<string, vector<pair<string, int>>> root;

public:
    void add(const string &u, const string &v, const int &w)
    {
        root[u].push_back({v, w});
        root[v].push_back({u, w});
    }

    void kruskal_mst()
    {
        vector<tuple<int, string, string>> edges;
        unordered_map<string, bool> vis;

        // Step 1: collect unique edges
        for (auto &u : root)
        {
            for (auto &v : u.second)
            {
                string e1 = u.first + "-" + v.first;
                string e2 = v.first + "-" + u.first;

                if (!vis[e1] && !vis[e2])
                {
                    edges.push_back({v.second, u.first, v.first});
                    vis[e1] = true;
                }
            }
        }

        // Step 2: sort edges
        sort(edges.begin(), edges.end());

        // Step 3: assign group id
        unordered_map<string, int> group;
        int id = 0;

        for (auto &i : root)
            group[i.first] = id++;

        int totalCost = 0;

        cout << "MST Edges:\n";

        // Step 4: process edges
        for (auto &e : edges)
        {
            int w = get<0>(e);
            string u = get<1>(e);
            string v = get<2>(e);

            if (group[u] != group[v])
            {
                cout << u << " - " << v << " : " << w << "\n";
                totalCost += w;

                int oldG = group[v];
                int newG = group[u];

                for (auto &i : group)
                {
                    if (i.second == oldG)
                        i.second = newG;
                }
            }
        }

        cout << "Total Cost: " << totalCost << "\n";
    }
};

int main()
{
    graphs gp;

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

    gp.kruskal_mst();

    return 0;
}