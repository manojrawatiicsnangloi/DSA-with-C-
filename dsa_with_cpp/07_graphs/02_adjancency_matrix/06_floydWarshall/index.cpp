#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Graph
{
    vector<vector<int>> dist;
    int V;

public:

    Graph(int v)
    {
        V = v;

        dist.resize(V,
                    vector<int>(V, INT_MAX));

        // self distance = 0
        for (int i = 0; i < V; i++)
        {
            dist[i][i] = 0;
        }
    }

    void addEdge(int u, int v, int w)
    {
        dist[u][v] = w;
    }

    void floydWarshall()
    {
        for (int k = 0; k < V; k++)
        {
            for (int i = 0; i < V; i++)
            {
                for (int j = 0; j < V; j++)
                {
                    // avoid overflow
                    if (dist[i][k] != INT_MAX &&
                        dist[k][j] != INT_MAX)
                    {
                        dist[i][j] = min(
                            dist[i][j],
                            dist[i][k] + dist[k][j]
                        );
                    }
                }
            }
        }
    }

    void print()
    {
        cout << "\nShortest Distance Matrix\n";

        for (int i = 0; i < V; i++)
        {

            for (int j = 0; j < V; j++)
            {

                if (dist[i][j] == INT_MAX)
                {
                    cout << "INF ";
                }
                else
                {
                    cout << dist[i][j] << " ";
                }
            }

            cout << "\n";
        }
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 3, 10);
    g.addEdge(1, 2, 3);
    g.addEdge(2, 3, 1);
    g.floydWarshall();
    g.print();
    return 0;
}