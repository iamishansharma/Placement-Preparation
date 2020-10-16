// { Driver Code Starts
// Initial template
#include <bits/stdc++.h>
using namespace std;

bool isBridge(list<int> adj[], int V, int u, int v);
// Driver Program
int main()
{

    int T;
    cin >> T;
    while (T--)
    {
        int s, N;
        cin >> s >> N;
        list<int> *adj = new list<int>[s];
        for (int i = 0; i < N; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int a, b;
        cin >> a >> b;

        if (isBridge(adj, s, a, b))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
}
// } Driver Code Ends

// your task is to complete this function

/*
adj : adjacency list of the graph
V : Number of vertices
s,e : End vertices of the given edge
*/
void DFS(list<int> adj[], vector<bool> &visited, int start)
{
    visited[start] = true;

    for (auto it = adj[start].begin(); it != adj[start].end(); it++)
        if (!visited[*it])
            DFS(adj, visited, *it);
}

bool isBridge(list<int> adj[], int V, int s, int e)
{
    adj[s].remove(e);
    adj[e].remove(s);

    vector<bool> visited(V, false);

    DFS(adj, visited, s);

    if (!visited[e])
        return true;
    else
        return false;
}