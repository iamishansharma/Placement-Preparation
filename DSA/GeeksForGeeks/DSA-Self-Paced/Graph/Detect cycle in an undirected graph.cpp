// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/* This function is used to detect a cycle in undirected graph

*  g[]: array of vectors to represent graph
*  V: number of vertices
*/
bool DFS(int start, vector<int> g[], vector<bool> &visited, int parent)
{
    visited[start] = true;

    for (int i = 0; i < g[start].size(); i++)
    {
        if (!visited[g[start][i]])
        {
            if (DFS(g[start][i], g, visited, start))
                return true;
        }
        else if (parent != g[start][i])
            return true;
    }
    return false;
}

bool BFS(int start, vector<int> g[], vector<bool> &visited, int parent)
{
    queue<pair<int, int>> q;
    q.push({start, -1});
    visited[start] = true;

    while (!q.empty())
    {
        pair<int, int> temp = q.front();
        q.pop();

        for (int i = 0; i < g[temp.first].size(); i++)
        {
            if (!visited[g[temp.first][i]])
            {
                visited[g[temp.first][i]] = true;
                q.push({g[temp.first][i], temp.first});
            }
            else if (temp.second != g[temp.first][i])
                return true;
        }
    }

    return false;
}

bool isCyclic(vector<int> g[], int V)
{
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++)
        if (!visited[i])
            if (BFS(i, g, visited, -1))
                return true;

    return false;
}

// { Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int V, E;
        cin >> V >> E;

        // array of vectors to represent graph
        vector<int> adj[V];

        int u, v;
        for (int i = 0; i < E; i++)
        {
            cin >> u >> v;

            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V) << endl;
    }
}
// } Driver Code Ends