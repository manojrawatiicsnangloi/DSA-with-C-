#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class graphs{
private:
    unordered_map<string, vector<pair<string, int>>> root;

public:
    void add(string u, string v, int w){
        root[u].push_back({v, w});
        root[v].push_back({u, w});
    }

    void astar(string start, string goal){
        priority_queue<
            pair<int, string>,
            vector<pair<int, string>>,
            greater<pair<int, string>>
        > pq;

        unordered_map<string, int> g;

        for (auto &i: root){
            g[i.first] = INT_MAX;
        }

        g[start] = 0;
        pq.push({0, start});

        while (!pq.empty()){
            auto top = pq.top();
            pq.pop();

            string node = top.second;

            // skip outdated
            if (top.first > g[node]) continue;

            // 🔥 stop when goal reached
            if (node == goal){
                cout << "\nGoal Reached : " << goal << endl;
                cout << "Cost : " << g[goal] << endl;
                return;
            }

            for (auto &i: root[node]){
                int newG = g[node] + i.second;

                if (newG < g[i.first]){
                    g[i.first] = newG;
                    pq.push({newG, i.first});
                }
            }
        }

        cout << "Goal not reachable\n";
    }
};


int main(){
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

    gp.astar("A", "E");
    return 0;
}