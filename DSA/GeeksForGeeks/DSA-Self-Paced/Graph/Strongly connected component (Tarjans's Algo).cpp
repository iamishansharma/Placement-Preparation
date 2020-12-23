// { Driver Code Starts
#include <bits/stdc++.h>
#define NIL -1
using namespace std;

void find(vector<int> adj[], int N);

int main()
{

    int t; // number of test cases
    cin >> t;

    while (t--)
    {

        int n, m;
        cin >> n >> m; // n- number of nodes and m- number of edges

        vector<int> adj[n + 1]; // adjacency list

        for (int i = 0; i < m; ++i)
        {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
        }

        find(adj, n);
        cout << "\n";
    }
} // } Driver Code Ends

// adj : adjacency list of the given graph
// V : number of vertices

void DFS(int u, vector<int> adj[], vector<bool> &recSt, stack<int> &st, vector<int> &disc, vector<int> &low, int &t)
{
    disc[u] = low[u] = t++;
    st.push(u);
    recSt[u] = true;

    for (int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];

        if (disc[v] == -1)
        {
            DFS(v, adj, recSt, st, disc, low, t);
            low[u] = min(low[u], low[v]);
        }
        else if (recSt[v] == true)
            low[u] = min(low[u], disc[v]);
    }

    if (low[u] == disc[u])
    {
        while (st.top() != u)
        {
            cout << st.top() << " ";
            recSt[st.top()] = false;
            st.pop();
        }
        cout << st.top() << ",";
        recSt[st.top()] = false;
        st.pop();
    }
}

void find(vector<int> adj[], int V)
{
    stack<int> st;
    vector<bool> recSt(V, false);
    vector<int> disc(V, -1);
    vector<int> low(V, -1);

    int t = 1;

    for (int i = 0; i < V; i++)
        if (disc[i] == -1)
            DFS(i, adj, recSt, st, disc, low, t);
}