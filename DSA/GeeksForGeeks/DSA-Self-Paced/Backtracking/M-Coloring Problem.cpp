// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

bool isSafe(int u, int currentColor, int V, bool graph[101][101], vector<int> &colors)
{
    for (int v = 0; v < V; v++)
        if (graph[u][v] == 1 && colors[v] == currentColor)
            return false;

    return true;
}

bool graphRec(int u, vector<int> &colors, int m, int V, bool graph[101][101])
{
    if (u == V)
        return true;

    for (int currentColor = 0; currentColor < m; currentColor++)
    {
        if (isSafe(u, currentColor, V, graph, colors))
        {
            colors[u] = currentColor;

            if (graphRec(u + 1, colors, m, V, graph))
                return true;

            colors[u] = -1;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int V)
{
    vector<int> colors(V, -1);

    return graphRec(0, colors, m, V, graph);
}

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++)
        {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++)
        {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
// } Driver Code Ends