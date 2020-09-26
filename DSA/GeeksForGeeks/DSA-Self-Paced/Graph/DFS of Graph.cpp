// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/* Function to do DFS of graph

g : adjacency list of graph
N : number of vertices

return a list containing the DFS traversal of the given graph
*/
void dfsrec(int s, vector<int> g[], vector<bool> vis, vector<int> &ans)
{
    vis[s] = true;

    ans.push_back(s);

    vector<int>::iterator i;

    for (i = g[s].begin(); i != g[s].end(); ++i)
    {
        if (!vis[*i])
            dfsrec(*i, g, vis, ans);
    }
}

vector<int> dfs(vector<int> g[], int N)
{

    // Iterative -

    int s = 0;
    vector<bool> vis(N, false);
    vector<int> ans;

    stack<int> st;
    st.push(s);

    ans.push_back(s);
    vis[s] = true;

    while (!st.empty())
    {
        int top = st.top();
        int flag = 0;

        for (int i = 0; i < g[top].size(); i++)
        {
            if (!vis[g[top][i]])
            {
                st.push(g[top][i]);

                ans.push_back(g[top][i]);

                vis[g[top][i]] = true;

                flag = 1;

                break;
            }
        }

        if (!flag)
            st.pop();
    }

    return ans;

    /* Recursive
    
    vector<bool> vis(N, false);
    vector<int> ans;
    
    dfsrec(0, g, vis, ans);
    
    return ans;*/
}

// { Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {

        int N, E;
        cin >> N >> E;

        vector<int> g[N];
        bool vis[N];

        memset(vis, false, sizeof(vis));

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<int> res = dfs(g, N);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
} // } Driver Code Ends