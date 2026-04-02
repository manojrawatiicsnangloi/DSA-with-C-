#include <iostream>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <climits>
#include <queue>

using namespace std;

class graphs
{
private:
    unordered_map<string, vector<pair<string, int>>> root;
    void _dfs(string s, unordered_map<string, bool> &visited){
    visited[s] = true;
    cout << s << ", ";
    for (auto&i : root[s]){
    if (!visited[i.first]){
            _dfs(i.first, visited);
        }
    } 
}
public:
    void add(string u, string v, int w)
    {
        root[u].push_back({v, w});
        root[v].push_back({u, w});
    }

    void bfs(string s)
    {

        cout << "\nbfs : ";
        unordered_map<string, bool> visited;
        queue<string> q;
        q.push(s);
        visited[s] = true;
        while (!q.empty())
        {
            string node = q.front();
            cout << node << ", ";
            q.pop();
            for (auto &i : root[node])
            {
                if (!visited[i.first])
                {
                    visited[i.first] = true;
                    q.push(i.first);
                }
            }
        }
    }
    
    void dfs(string s){
        cout << "\nDFS : ";
        unordered_map<string, bool> vis;
        _dfs(s, vis);
    }

    void printGraph()
    {
        for (auto &i : root)
        {
            cout << i.first << " : ";
            for (pair<string, int> &j : i.second)
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
    gp.printGraph();
    gp.bfs("A");
    gp.dfs("A");
    return 0;
}