// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int spanningTree(int V, int E, vector<vector<int>> &graph);
// Driver code

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> graph(V, vector<int>(V, INT_MAX));
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            graph[u][v] = w;
            graph[v][u] = w;
        }

        cout << spanningTree(V, E, graph) << endl;
    }
    return 0;
}
// } Driver Code Ends

// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation, with V vertices.
// graph[i][j] = weight if edge exits else INT_MAX

int spanningTree(int V, int E, vector<vector<int>> &graph)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push(make_pair(0, 0));

    int sum = 0;
    vector<bool> vis(V, false);

    while (!pq.empty())
    {
        int len = pq.size();

        while (len--)
        {
            pair<int, int> p = pq.top();
            pq.pop();

            if (vis[p.second] == false)
            {
                sum += p.first;
                vis[p.second] = true;

                for (int i = 0; i < V; i++)
                {
                    if (graph[p.second][i] != INT_MAX)
                    {
                        if (!vis[i])
                            pq.push(make_pair(graph[p.second][i], i));
                    }
                }
            }
        }
    }

    return sum;
}