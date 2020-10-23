// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

/*  Function to check if there is cycle in graph
*   adj[]: array of vectors to represent graph
*   n and e are number of nodes and edges respectively
*   parent[]: array to store parent of nodes. Each index stores its node value
* initially
*   rank1[]: Each node from 1 to n store initial size as 1.
*/
int find(int parent[], int x)
{
    if (parent[x] == x)
        return x;

    return parent[x] = find(parent, parent[x]);
}

bool unionNodes(int a, int b, int parent[], int rank[])
{
    int pa = find(parent, a);
    int pb = find(parent, b);

    if (pa == pb)
        return true;
    else
    {
        if (rank[pa] < rank[pb])
        {
            parent[pa] = pb;
            rank[pb]++;
        }
        else
        {
            parent[pb] = pa;
            rank[pa]++;
        }

        return false;
    }
}

bool findCycle(vector<int> adj[], int parent[], int rank[], int n, int e)
{
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < adj[i].size(); j++)
            if (i < adj[i][j] && unionNodes(i, adj[i][j], parent, rank))
                return true;

    return false;
}

// { Driver Code Starts.

int main()
{

    //taking total count of testcases
    int t;
    cin >> t;

    while (t--)
    {

        //taking total count of
        //nodes and edges
        int n, e;
        cin >> n >> e;
        vector<int> adj[n + 1];

        int parent[n + 1];

        int rank1[n + 1];

        //adding nodes in adjacency vector
        for (int i = 0; i < e; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // makeSet operation
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
            rank1[i] = 1;
        }

        //calling function findCycle()
        if (findCycle(adj, parent, rank1, n, e))
        {
            cout << "1";
        }
        else
            cout << "0";

        cout << endl;
    }

    return 0;
}
// } Driver Code Ends