#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class graphs
{
    vector<vector<int>> root;
  public : graphs(int size)
    {
        root.resize(size, vector<int>(size, 0));

        // Every node can reach itself
        for (int i = 0; i < size; i++)
        {
            root[i][i] = 1;
        }
    }

    void addEdge(int u, int v, int w)
    {
        root[u][v] = 1;
    }

    void floydWarshallAlgo()
    {
        for (int k = 0; k < root.size(); k++)
        {
            for (int i = 0; i < root.size(); i++)
            {
                for (int j = 0; j < root.size(); j++)
                {
                        root[i][j] = root[i][j] || (root[i][k] && root[k][j]);
                }
            }
        }
    }

    void printGraph(){
        for (int i = 0; i < root.size(); i++){
            for (int j = 0; j < root.size(); j++){
                if(root[i][j] == INT_MAX){
                    cout << "X ";
                }else{
                    cout << root[i][j] << " ";
                }
            }
            cout << endl;
        }
    }
};

int main()
{
    graphs g(4);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 3, 10);
    g.addEdge(1, 2, 3);
    g.addEdge(2, 3, 1);
    g.printGraph();
    return 0;
}