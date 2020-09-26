// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/* This function is used to detect a cycle in undirected graph

*  g[]: array of vectors to represent graph
*  V: number of vertices
*/

// Recursive DFS

/*bool isCyclicUtil(vector<int> g[],bool* visited,int sv,int parent)
{
    visited[sv] = true;
    
    for(int i=0;i<g[sv].size();i++)
    {
        if(visited[g[sv][i]] == false)
        {
            if(isCyclicUtil(g,visited,g[sv][i],sv))
                return true;
        }
        else if(parent != g[sv][i])
        {
            return true;
        }
    }
    return false;
}
bool isCyclic(vector<int> g[], int V)
{
    bool* visited = new bool [V];
    
    for(int i=0; i<V; i++)
    {
        visited[i] = false;
    }
    
    for(int i=0; i<V; i++)
    {
        if(visited[i] == false)
        {
            if(isCyclicUtil(g,visited,i,-1))
                return true;
        }
    }
    return false;
}*/

// Iterative BFS

bool BFS(int start, vector<int> g[], vector<bool> &visited, int V)
{
    vector<int> parent(V, -1);

    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto v : g[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
                parent[v] = u;
            }
            else if (parent[u] != v)
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
            if (BFS(i, g, visited, V))
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