// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/

bool DFS(int start, vector<int> g[], vector<bool> &visited, vector<bool> &recSt)
{
    visited[start] = true;
    recSt[start] = true;

    for (int i = 0; i < g[start].size(); i++)
    {
        int u = g[start][i];

        if (!visited[u])
        {
            if (DFS(u, g, visited, recSt))
                return true;
        }
        else if (recSt[u] == true)
            return true;
    }

    recSt[start] = false;
    return false;
}

bool isCyclic(int V, vector<int> g[])
{
    // vector<bool> recSt(V, false);
    // vector<bool> visited(V, false);

    // for (int i = 0; i < V; i++)
    //     if (!visited[i])
    //         if (DFS(i, g, visited, recSt))
    //             return true;

    // return false;

    int count = 0;

    vector<int> indegree(V, 0);

    for (int i = 0; i < V; i++)
        for (int j = 0; j < g[i].size(); j++)
            indegree[g[i][j]]++;

    queue<int> q;

    for (int i = 0; i < V; i++)
        if (indegree[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        int fr = q.front();
        q.pop();

        for (int i = 0; i < g[fr].size(); i++)
        {
            int v = g[fr][i];

            indegree[v]--;

            if (indegree[v] == 0)
                q.push(v);
        }

        count++;
    }

    return count != V;
}

// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;

    while (t--)
    {

        int v, e;
        cin >> v >> e;

        vector<int> adj[v];

        for (int i = 0; i < e; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        cout << isCyclic(v, adj) << endl;
    }

    return 0;
} // } Driver Code Ends