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

void DFS(int u, list<int> adj[], vector<int> &disc, vector<int> &parent, vector<int> &low, int &t)
{
    disc[u] = low[u] = t++;

    for (auto it = adj[u].begin(); it != adj[u].end(); it++)
    {
        int v = *it;

        if (disc[v] == -1)
        {
            parent[v] = u;

            DFS(v, adj, disc, parent, low, t);

            low[u] = min(low[u], low[v]);

            // if(low[v] > disc[u])
            //     cout<<"This is the one: "<<u<<" "<<v<<endl;
        }
        else if (v != parent[u])
            low[u] = min(low[u], disc[v]);
    }
}

bool isBridge(list<int> adj[], int V, int s, int e)
{
    vector<int> disc(V, -1);
    vector<int> parent(V, -1);
    vector<int> low(V, -1);

    int t = 1;

    for (int i = 0; i < V; i++)
        if (disc[i] == -1)
            DFS(i, adj, disc, parent, low, t);
    //cout<<endl;
    return low[e] > disc[s] || low[s] > disc[e];
}