// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

vector<int> topoSort(int N, vector<int> adj[]);

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
bool check(int V, vector<int> &res, vector<int> adj[])
{
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++)
    {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++)
    {
        for (int v : adj[i])
        {
            if (map[i] > map[v])
                return false;
        }
    }
    return true;
}

// Driver Code
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        vector<int> res = topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
} // } Driver Code Ends

// The Graph structure is as folows

/*  Function which sorts the graph vertices in topological form
*   N: number of vertices
*   adj[]: input graph
*/
vector<int> BFS_Kahns(int V, vector<int> g[])
{
    vector<int> indegree(V, 0);
    vector<int> ans;
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++)
        for (int j = 0; j < g[i].size(); j++)
            indegree[g[i][j]]++;

    queue<int> q;

    for (int i = 0; i < V; i++)
        if (indegree[i] == 0)
        {
            visited[i] = true;
            q.push(i);
        }

    while (!q.empty())
    {
        int temp = q.front();
        q.pop();

        ans.push_back(temp);

        for (int i = 0; i < g[temp].size(); i++)
        {
            int v = g[temp][i];

            indegree[v]--;

            if (indegree[v] == 0)
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    return ans;
}

void DFS_Stack(int start, vector<int> g[], vector<bool> &visited, stack<int> &s)
{
    visited[start] = true;

    for (int i = 0; i < g[start].size(); i++)
    {
        if (!visited[g[start][i]])
            DFS_Stack(g[start][i], g, visited, s);
    }

    s.push(start);
}

vector<int> topoSort(int V, vector<int> g[])
{
    // return BFS_Kahns(V, g);

    vector<bool> visited(V, false);
    stack<int> s;
    vector<int> ans;

    for (int i = 0; i < V; i++)
        if (!visited[i])
            DFS_Stack(i, g, visited, s);

    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
