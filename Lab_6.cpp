#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define edge pair<int, int>

vector<pair<int, edge>> G;
vector<pair<int, edge>> T;
int *parent;

void Init(int N)
{
    parent = new int[N];

    for (int i = 0; i < N; i++)
    {
        parent[i] = i;
    }

    G.clear();
    T.clear();
}

int find_set(int i)
{
    if (i == parent[i])
        return i;
    else
        return find_set(parent[i]);
}

void union_set(int u, int v)
{
    parent[u] = parent[v];
}

void Kruskal()
{
    int i, uRep, vRep;
    sort(G.begin(), G.end());
    for (i = 0; i < G.size(); i++)
    {
        uRep = find_set(G[i].second.first);
        vRep = find_set(G[i].second.second);
        if (uRep != vRep)
        {
            T.push_back(G[i]);
            union_set(uRep, vRep);
        }
    }
}

void PrintGraphAdjacencyList()
{
    cout << "\nGraph adjacency list:" << endl;
    for (int i = 0; i < T.size(); i++)
    {
        cout << T[i].second.first << " - " << T[i].second.second << " : " << T[i].first;
        cout << endl;
    }
}

int main()
{
    int N, M;

    cout << "Nodes: ";
    cin >> N;

    cout << "Edges: ";
    cin >> M;

    if (1 >= N || M > 256)
    {
        std::cout << "Incorrect value\n";
        system("pause");
        return 0;
    }

    Init(N);

    for (int i = 0; i < M; i++)
    {
        int u, v, w;

        cout << "Node 1, Node 2, Weight: ";
        cin >> u >> v >> w;

        G.push_back(make_pair(w, edge(u, v)));
    }

    // AddWeightedEdge(0, 1, 4);
    // AddWeightedEdge(0, 2, 4);
    // AddWeightedEdge(1, 2, 2);
    // AddWeightedEdge(1, 0, 4);
    // AddWeightedEdge(2, 0, 4);
    // AddWeightedEdge(2, 1, 2);
    // AddWeightedEdge(2, 3, 3);
    // AddWeightedEdge(2, 5, 2);
    // AddWeightedEdge(2, 4, 4);
    // AddWeightedEdge(3, 2, 3);
    // AddWeightedEdge(3, 4, 3);
    // AddWeightedEdge(4, 2, 4);
    // AddWeightedEdge(4, 3, 3);
    // AddWeightedEdge(5, 2, 2);
    // AddWeightedEdge(5, 4, 3);

    Kruskal();
    PrintGraphAdjacencyList();

    system("pause");

    return 0;
}