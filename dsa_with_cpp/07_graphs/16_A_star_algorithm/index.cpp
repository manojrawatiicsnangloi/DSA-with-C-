#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class graphs{
    private:
    unordered_map <string, vector<pair<string, int>>> root;
    public:
    void add(string u, string v, int w){
        root[u].push_back({v, w});
        root[v].push_back({u, w});
    }

    void dikastra(string s){
        priority_queue<
        pair<int, string>,
        vector<pair<int, string>>,
        greater<pair<int, string>>
        > pq;
        unordered_map<string, int> dist;
        for (auto&i: root){
            dist[i.first] = INT_MAX;
        }
        dist[s] = 0;
        pq.push({0, s});
        while (!pq.empty()){
            pair<int, string> top = pq.top();
            pq.pop();
            if (top.first > dist[top.second]) continue;
            for (auto &i: root[top.second]){
                int totalWeight = top.first + i.second; 
                if (dist[i.first] > totalWeight){
                    pq.push({totalWeight, i.first});
                    dist[i.first] = totalWeight;
                }
            }
        }
        for (auto &i: dist){
            cout << endl;
            cout << i.first << " " << i.second ;
        }
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

            if (top.second == goal) {
                cout << "\nGoal Reached : " << goal << endl;
                cout << "Cost : " << g[goal];
                return;
            }
            if (g[top.second] < top.first) continue;
            for (auto &i: root[top.second]){
                int totalDistance = top.first + i.second;
                if (totalDistance < g[i.first]){
                    pq.push({totalDistance, i.first});
                    g[i.first] = totalDistance;
                }
            }
        }
        cout << "Goal not reachable\n";
    }
    void printGraph(){
        for (auto &i: root){
            cout << endl;
            cout << i.first << " : ";
            for (auto &j :i.second){
                cout << "("<<j.first << ", " << j.second << ") ";
            }
        }
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
    // gp.printGraph();
    // gp.dikastra("A");
    gp.astar("A", "E");
    return 0;
}