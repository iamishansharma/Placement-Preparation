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
// N : number of vertices
void SCCUtil(int u, vector<int> adj[], vector<int> &disc, vector<int> &low, stack<int> &st, vector<bool> &stackMember)
{
    static int time = 0;

    // Initialize discovery time and low value
    disc[u] = low[u] = ++time;
    st.push(u);
    stackMember[u] = true;

    // Go through all vertices adjacent to this
    for (auto i = adj[u].begin(); i != adj[u].end(); ++i)
    {
        int v = *i; // v is current adjacent of 'u'

        // If v is not visited yet, then recur for it
        if (disc[v] == -1)
        {
            SCCUtil(v, adj, disc, low, st, stackMember);

            // Check if the subtree rooted with 'v' has a
            // connection to one of the ancestors of 'u'
            // Case 1 (per above discussion on Disc and Low value)
            low[u] = min(low[u], low[v]);
        }

        // Update low value of 'u' only of 'v' is still in stack
        // (i.e. it's a back edge, not cross edge).
        // Case 2 (per above discussion on Disc and Low value)
        else if (stackMember[v] == true)
            low[u] = min(low[u], disc[v]);
    }

    // head node found, pop the stack and print an SCC
    int w = 0; // To store stack extracted vertices
    if (low[u] == disc[u])
    {
        while (st.top() != u)
        {
            w = st.top();
            cout << w << " ";
            stackMember[w] = false;
            st.pop();
        }
        w = st.top();
        cout << w << ",";
        stackMember[w] = false;
        st.pop();
    }
}

void find(vector<int> adj[], int V)
{
    vector<int> disc(V, -1);
    vector<int> low(V, -1);
    vector<bool> stackMember(V, false);
    stack<int> st;

    for (int i = 0; i < V; i++)
        if (disc[i] == -1)
            SCCUtil(i, adj, disc, low, st, stackMember);
}