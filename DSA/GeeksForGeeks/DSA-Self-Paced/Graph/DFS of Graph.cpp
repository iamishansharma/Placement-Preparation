// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/* Function to do DFS of graph

g : adjacency list of graph
N : number of vertices

return a list containing the DFS traversal of the given graph
*/
void recursive(int start, vector<int> g[], int N, vector<int> &ans, vector<bool> &visited)
{
    visited[start] = true;
    ans.push_back(start);

    for (int i = 0; i < g[start].size(); i++)
    {
        if (!visited[g[start][i]])
        {
            visited[g[start][i]] = true;
            recursive(g[start][i], g, N, ans, visited);
        }
    }
}
void iterative(int start, vector<int> g[], int N, vector<int> &ans, vector<bool> &visited)
{
    stack<int> s;
    s.push(start);

    ans.push_back(start);
    visited[start] = true;

    while (!s.empty())
    {
        int top = s.top();
        int flag = 0;

        for (int i = 0; i < g[top].size(); i++)
        {
            if (!visited[g[top][i]])
            {
                ans.push_back(g[top][i]);
                visited[g[top][i]] = true;
                s.push(g[top][i]);

                flag = 1;

                break;
            }
        }

        if (!flag)
            s.pop();
    }
}

vector<int> dfs(vector<int> g[], int N)
{
    vector<int> ans;
    vector<bool> visited(N);

    recursive(0, g, N, ans, visited);
    //iterative(0, g, N, ans, visited);

    return ans;
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