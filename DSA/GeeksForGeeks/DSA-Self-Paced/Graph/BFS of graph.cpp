// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

vector <int> bfs(vector<int> g[], int N);

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        vector<int> adj[N];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        vector <int> res = bfs(adj, N);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        cout << endl;
    }
}// } Driver Code Ends


/* You have to complete this function*/

/* Function to do BFS of graph
*  g[]: adj list of the graph
*  N : number of vertices
*/
vector<int> bfs(vector<int> g[], int N) 
{
    int s = 0;
    vector<bool> visited(N, false);

    vector<int> ans;
    
    queue<int> q;
    q.push(s);
    visited[s] = true;
    
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        
        ans.push_back(node);
        
        for(auto i:g[node])
            if(!visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
    }
    
    return ans;
}