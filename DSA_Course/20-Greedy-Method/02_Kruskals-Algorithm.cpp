#include<iostream>
#include<climits>
using namespace std;

struct Edge
{
    int u, v, cost;
};

class DisjointSet
{
    int parent[101];
    int rank[101];

public:

    DisjointSet(int n)
    {
        for(int i = 1; i <= n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int Find(int x)
    {
        if(parent[x] != x)
            parent[x] = Find(parent[x]);

        return parent[x];
    }

    void Union(int x, int y)
    {
        x = Find(x);
        y = Find(y);

        if(x == y)
            return;

        if(rank[x] < rank[y])
            parent[x] = y;

        else if(rank[x] > rank[y])
            parent[y] = x;

        else
        {
            parent[y] = x;
            rank[x]++;
        }
    }
};

int main()
{
    int n, e;

    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;

    if(n <= 0 || n > 100 || e < 0 || e > 5000)
    {
        cout << "Invalid graph size";
        return 0;
    }

    Edge edges[5000];
    bool selected[5000] = {false};

    cout << "Enter edges (u v cost), vertices numbered 1 to "
         << n << ":\n";

    for(int i = 0; i < e; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].cost;

        if(edges[i].u < 1 || edges[i].u > n ||
           edges[i].v < 1 || edges[i].v > n ||
           edges[i].u == edges[i].v)
        {
            cout << "Invalid edge";
            return 0;
        }
    }

    DisjointSet ds(n);

    int edgeCount = 0;
    long long minCost = 0;

    cout << "Edges in Minimum Spanning Tree:\n";

    while(edgeCount < n - 1)
    {
        int min = INT_MAX;
        int index = -1;

        // Find the minimum-cost edge not yet considered.

        for(int i = 0; i < e; i++)
        {
            if(!selected[i] && edges[i].cost < min)
            {
                min = edges[i].cost;
                index = i;
            }
        }

        if(index == -1)
            break;

        int u = edges[index].u;
        int v = edges[index].v;

        selected[index] = true;

        // Include edge only if it does not form a cycle.

        if(ds.Find(u) != ds.Find(v))
        {
            cout << u << " - " << v
                 << " : " << edges[index].cost << endl;

            minCost += edges[index].cost;

            ds.Union(u, v);
            edgeCount++;
        }
    }

    if(edgeCount != n - 1)
        cout << "Graph is disconnected; MST does not exist.\n";

    else
        cout << "Minimum cost = " << minCost << endl;

    return 0;
}