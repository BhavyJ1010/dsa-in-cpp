#include<iostream>
#include<climits>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of vertices: ";
    cin >> n;

    if(n <= 0 || n > 100)
    {
        cout << "Invalid number of vertices";
        return 0;
    }

    int cost[101][101];
    int near[101];
    bool selected[101] = {false};

    cout << "Enter adjacency matrix (0 for no edge, diagonal 0):\n";

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> cost[i][j];

    int start;

    cout << "Enter starting vertex: ";
    cin >> start;

    if(start < 1 || start > n)
    {
        cout << "Invalid starting vertex";
        return 0;
    }

    selected[start] = true;

    for(int i = 1; i <= n; i++)
    {
        if(i == start || cost[start][i] == 0)
            near[i] = -1;

        else
            near[i] = start;
    }

    int edgeCount = 0;
    long long minCost = 0;

    cout << "Edges in Minimum Spanning Tree:\n";

    while(edgeCount < n - 1)
    {
        int min = INT_MAX;
        int v = -1;

        // Find the minimum edge connecting the MST
        // to an unselected vertex.

        for(int i = 1; i <= n; i++)
        {
            if(!selected[i] && near[i] != -1 &&
               cost[i][near[i]] < min)
            {
                min = cost[i][near[i]];
                v = i;
            }
        }

        if(v == -1)
        {
            cout << "Graph is disconnected; MST does not exist.\n";
            return 0;
        }

        int u = near[v];

        cout << u << " - " << v
             << " : " << cost[u][v] << endl;

        minCost += cost[u][v];

        selected[v] = true;
        near[v] = -1;
        edgeCount++;

        // Update near[] for remaining vertices.

        for(int i = 1; i <= n; i++)
        {
            if(!selected[i] && cost[i][v] != 0)
            {
                if(near[i] == -1 ||
                   cost[i][v] < cost[i][near[i]])
                {
                    near[i] = v;
                }
            }
        }
    }

    cout << "Minimum cost = " << minCost << endl;

    return 0;
}