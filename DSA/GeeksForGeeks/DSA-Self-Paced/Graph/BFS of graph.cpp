// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

vector<int> bfs(vector<int> g[], int N);

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, E;
        cin >> N >> E;
        vector<int> adj[N];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        vector<int> res = bfs(adj, N);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
} // } Driver Code Ends

/* You have to complete this function*/

/* Function to do BFS of graph
*  g[]: adj list of the graph
*  N : number of vertices
*/
vector<int> bfs(vector<int> adj[], int N)
{
    vector<int> ans;

    vector<bool> visited(N);
    visited[0] = true;
    queue<int> q;
    q.push(0);

    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        ans.push_back(front);

        for (int i = 0; i < adj[front].size(); i++)
        {
            if (!visited[adj[front][i]])
            {
                visited[adj[front][i]] = true;
                q.push(adj[front][i]);
            }
        }
    }

    return ans;
}