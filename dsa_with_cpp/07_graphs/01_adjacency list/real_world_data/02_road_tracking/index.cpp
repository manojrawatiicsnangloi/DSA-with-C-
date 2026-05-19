#include <iostream>
#include <cfloat>
#include <algorithm>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <queue>
#include <sstream>
#include <cmath>

using namespace std;

class node
{
public:
    node *children[26];

    bool isEnd;

    vector<int> stationIds;

    vector<string> stationNames;

    node()
    {
        isEnd = false;

        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }
};

class trie
{
private:
    node *root;

public:
    trie()
    {
        root = new node();
    }

    string cleanWord(string word)
    {
        string result;

        for (char c : word)
        {
            c = tolower(c);

            if (c >= 'a' && c <= 'z')
            {
                result += c;
            }
        }

        return result;
    }

    void insert(string word, int stationId)
    {
        string original = word;

        word = cleanWord(word);

        node *temp = root;

        for (char c : word)
        {
            int index = c - 'a';

            if (temp->children[index] == NULL)
            {
                temp->children[index] = new node();
            }

            temp = temp->children[index];
        }

        temp->isEnd = true;

        temp->stationIds.push_back(stationId);

        temp->stationNames.push_back(original);
    }

    bool search(string word)
    {
        word = cleanWord(word);

        node *temp = root;

        for (char i : word)
        {
            int index = i - 'a';

            if (temp->children[index] == NULL)
                return false;

            temp = temp->children[index];
        }

        return temp->isEnd;
    }

    void collectWords(
        node *n,
        vector<pair<string, int>> &result)
    {
        if (n->isEnd)
        {
            for (int i = 0;
                 i < n->stationIds.size();
                 i++)
            {
                result.push_back({
                    n->stationNames[i],
                    n->stationIds[i]
                });
            }
        }

        for (int i = 0; i < 26; i++)
        {
            if (n->children[i] != NULL)
            {
                collectWords(
                    n->children[i],
                    result
                );
            }
        }
    }

    vector<pair<string, int>>
    autoComplete(string prefix)
    {
        prefix = cleanWord(prefix);

        node *temp = root;

        for (char c : prefix)
        {
            int index = c - 'a';

            if (temp->children[index] == NULL)
            {
                return {};
            }

            temp = temp->children[index];
        }

        vector<pair<string, int>> result;

        collectWords(temp, result);

        return result;
    }

    bool startWith(string prefix)
    {
        prefix = cleanWord(prefix);

        node *temp = root;

        for (char i : prefix)
        {
            int index = i - 'a';

            if (temp->children[index] == NULL)
                return false;

            temp = temp->children[index];
        }

        return true;
    }
};

class Graph
{
private:
    unordered_map<
        int,
        vector<pair<int, double>>
    > root;

public:
    void addEdge(int u, int v, double w)
    {
        root[u].push_back({v, w});

        root[v].push_back({u, w});
    }

    void dijkstra(
        int source,
        int destination,
        unordered_map<int, string>
            &stationNames)
    {
        if (root.find(source) == root.end())
        {
            cout << "Invalid Source\n";
            return;
        }

        if (root.find(destination) == root.end())
        {
            cout << "Invalid Destination\n";
            return;
        }

        unordered_map<int, double> dist;

        unordered_map<int, int> parent;

        for (auto &node : root)
        {
            int u = node.first;

            dist[u] = DBL_MAX;
        }

        dist[source] = 0;

        priority_queue<
            pair<double, int>,
            vector<pair<double, int>>,
            greater<pair<double, int>>
        > pq;

        pq.push({0, source});

        while (!pq.empty())
        {
            auto top = pq.top();

            pq.pop();

            double currentDistance =
                top.first;

            int currentNode =
                top.second;

            if (
                currentDistance
                > dist[currentNode]
            )
            {
                continue;
            }

            for (auto &neighbor :
                 root[currentNode])
            {
                int nextNode =
                    neighbor.first;

                double weight =
                    neighbor.second;

                if (
                    currentDistance + weight
                    < dist[nextNode]
                )
                {
                    dist[nextNode] =
                        currentDistance + weight;

                    parent[nextNode] =
                        currentNode;

                    pq.push({
                        dist[nextNode],
                        nextNode
                    });
                }
            }
        }

        if (dist[destination] == DBL_MAX)
        {
            cout << "No Path Found\n";
            return;
        }

        cout
            << "Shortest Distance = "
            << dist[destination]
            << "\n\n";

        vector<int> path;

        int current = destination;

        while (current != source)
        {
            path.push_back(current);

            if (
                parent.find(current)
                == parent.end()
            )
            {
                cout << "Broken Path\n";
                return;
            }

            current = parent[current];
        }

        path.push_back(source);

        reverse(
            path.begin(),
            path.end()
        );

        cout << "Path:\n\n";

        for (int id : path)
        {
            cout
                << stationNames[id]
                << endl;
        }
    }
};

struct Station
{
    int id;

    string name;

    double distance;

    string line;
};

int main()
{
    ifstream file("metro.csv");

    if (!file.is_open())
    {
        cout << "File not found\n";

        return 0;
    }

    Graph graph;

    trie t;

    unordered_map<
        int,
        string
    > stationNames;

    unordered_map<
        string,
        vector<Station>
    > metroLines;

    // IMPORTANT
    // for interchange stations
    unordered_map<
        string,
        vector<int>
    > sameStations;

    string row;

    while (getline(file, row))
    {
        if (row.empty())
            continue;

        stringstream ss(row);

        string idStr;
        string name;
        string distStr;
        string line;
        string opened;
        string layout;
        string lat;
        string lon;

        getline(ss, idStr, ',');
        getline(ss, name, ',');
        getline(ss, distStr, ',');
        getline(ss, line, ',');
        getline(ss, opened, ',');
        getline(ss, layout, ',');
        getline(ss, lat, ',');
        getline(ss, lon, ',');

        try
        {
            Station current;

            current.id =
                stoi(idStr);

            current.name =
                name;

            current.distance =
                stod(distStr);

            current.line =
                line;

            stationNames[current.id] =
                current.name;

            t.insert(
                current.name,
                current.id
            );

            metroLines[current.line]
                .push_back(current);

            // GROUP SAME NAME STATIONS
            string cleaned =
                t.cleanWord(current.name);

            sameStations[cleaned]
                .push_back(current.id);
        }
        catch (...)
        {
            continue;
        }
    }

    file.close();

    cout << "Stations Loaded\n";

    // SORT EACH LINE
    for (auto &linePair :
         metroLines)
    {
        vector<Station> &stations =
            linePair.second;

        sort(
            stations.begin(),
            stations.end(),
            [](Station &a,
               Station &b)
            {
                return
                    a.distance
                    < b.distance;
            }
        );
    }

    cout << "Stations Sorted\n";

    // BUILD NORMAL EDGES
    for (auto &linePair :
         metroLines)
    {
        vector<Station> &stations =
            linePair.second;

        for (
            int i = 0;
            i + 1 < stations.size();
            i++
        )
        {
            Station current =
                stations[i];

            Station next =
                stations[i + 1];

            double weight =
                std::abs(
                    next.distance
                    - current.distance
                );

            graph.addEdge(
                current.id,
                next.id,
                weight
            );
        }
    }

    // BUILD INTERCHANGE EDGES
    for (auto &pair : sameStations)
    {
        vector<int> &ids =
            pair.second;

        if (ids.size() > 1)
        {
            for (int i = 0;
                 i < ids.size();
                 i++)
            {
                for (int j = i + 1;
                     j < ids.size();
                     j++)
                {
                    // small transfer cost
                    graph.addEdge(
                        ids[i],
                        ids[j],
                        0.2
                    );
                }
            }
        }
    }

    cout
        << "Metro Graph Built Successfully\n\n";

    string prefix;

    // SOURCE

    cout
        << "Search Source Station: ";

    getline(cin, prefix);

    vector<pair<string, int>>
        sourceSuggestions =
            t.autoComplete(prefix);

    if (sourceSuggestions.empty())
    {
        cout
            << "No Source Station Found\n";

        return 0;
    }

    cout
        << "\nSource Suggestions:\n";

    for (auto &s :
         sourceSuggestions)
    {
        cout
            << s.first
            << " -> ID: "
            << s.second
            << endl;
    }

    int source;

    cout
        << "\nSelect Source ID: ";

    cin >> source;

    cin.ignore();

    // DESTINATION

    cout
        << "\nSearch Destination Station: ";

    getline(cin, prefix);

    vector<pair<string, int>>
        destSuggestions =
            t.autoComplete(prefix);

    if (destSuggestions.empty())
    {
        cout
            << "No Destination Station Found\n";

        return 0;
    }

    cout
        << "\nDestination Suggestions:\n";

    for (auto &s :
         destSuggestions)
    {
        cout
            << s.first
            << " -> ID: "
            << s.second
            << endl;
    }

    int destination;

    cout
        << "\nSelect Destination ID: ";

    cin >> destination;

    cout
        << "\nRunning Dijkstra...\n\n";

    graph.dijkstra(
        source,
        destination,
        stationNames
    );

    return 0;
}