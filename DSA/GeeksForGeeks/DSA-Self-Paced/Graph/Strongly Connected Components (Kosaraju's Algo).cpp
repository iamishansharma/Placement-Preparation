// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

/*  Function to find the number of strongly connected components
*   using Kosaraju's algorithm
*   V: number of vertices
*   adj[]: array of vectors to represent graph
*/
void getStack(int start, vector<int> g[], vector<bool> &visited, stack<int> &s)
{
    visited[start] = true;

    for (int i = 0; i < g[start].size(); i++)
        if (!visited[g[start][i]])
            getStack(g[start][i], g, visited, s);

    s.push(start);
}

void DFS(int start, vector<int> g[], vector<bool> &visited)
{
    visited[start] = true;

    for (int i = 0; i < g[start].size(); i++)
        if (!visited[g[start][i]])
            DFS(g[start][i], g, visited);
}

int kosaraju(int V, vector<int> g[])
{
    vector<bool> visited(V, false);
    stack<int> s;

    for (int i = 0; i < V; i++)
        if (!visited[i])
            getStack(i, g, visited, s);

    vector<int> reversed[V];

    for (int i = 0; i < V; i++)
        for (int j = 0; j < g[i].size(); j++)
            reversed[g[i][j]].push_back(i);

    for (int i = 0; i < V; i++)
        visited[i] = false;

    int scc = 0;

    while (!s.empty())
    {
        int u = s.top();
        s.pop();

        if (!visited[u])
        {
            DFS(u, reversed, visited);
            scc++;
        }
    }

    return scc;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int m, n;
        vector<int> adj[a];
        for (int i = 0; i < b; i++)
        {
            cin >> m >> n;
            adj[m].push_back(n);
        }
        cout << kosaraju(a, adj) << endl;
    }
    return 0;
}
// } Driver Code Ends