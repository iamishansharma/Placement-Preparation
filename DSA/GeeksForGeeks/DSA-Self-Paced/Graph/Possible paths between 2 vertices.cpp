// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Position this line where user code will be pasted.
int countPaths(list<int> g[], int V, int s, int d);
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, M;
        cin >> N >> M;
        int u, v;
        list<int> *adj = new list<int>[N + 1];
        while (M--)
        {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        int s, e;
        cin >> s >> e;
        cout << countPaths(adj, N, s, e) << endl;
    }
    return 0;
} // } Driver Code Ends

// The Graph structure is as folows
/*
g : Adjacency list of the graph
s : source node
d : destination node
V : number of vertices
*/

// Function to find paths between 2 nodes

void DFSRec(list<int> adj[], int s, int d, int visited[])
{
    visited[s] += 1;

    for (int u : adj[s])
        DFSRec(adj, u, d, visited);
}

int countPaths(list<int> adj[], int V, int s, int d)
{
    int visited[V + 1] = {0};

    DFSRec(adj, s, d, visited);

    return visited[d];
}