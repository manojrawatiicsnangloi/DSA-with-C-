#include <iostream>
#include <unordered_map>
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>
using namespace std;

class graphs
{
private:
    unordered_map<string, vector<pair<string, int>>> root;

    // DSU structures
    unordered_map<string, string> parent;

public:
    // Undirected graph
    void add(const string &u, const string &v, const int &w)
    {
        root[u].push_back({v, w});
        root[v].push_back({u, w});
    }

        void mst_prism(string s) {
            unordered_map<string, bool> vis;
            priority_queue<
            tuple<int, string, string>,
            vector<tuple<int, string, string>>,
            greater<tuple<int, string, string>>
            > pq;

            int totalWeight = 0;
            pq.push({0, s, ""});
            while (!pq.empty()){
                tuple<int, string, string> top = pq.top();
                int w = get<0>(top);
                string node = get<1>(top);
                string parent = get<2>(top);
                pq.pop();
                if (vis[node]) continue;
                vis[node] = true;
                if (parent != ""){
                    cout << parent << "--" << node << "\n" ;
                }
                totalWeight += w;
                for (auto &i: root[node]){
                     if (!vis[i.first]) {
                    pq.push({i.second, i.first, node});
                     }
                }
            }
            cout << endl << "Weight : " << totalWeight;
        };
    void printGraph()
    {
        for (auto &i : root)
        {
            cout << i.first << " : ";
            for (auto &j : i.second)
            {
                cout << "(" << j.first << ", " << j.second << ") ";
            }
            cout << "\n";
        }
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

    // gp.printGraph();

    // gp.mst(); //  call MST
    gp.mst_prism("A");
    return 0;
}