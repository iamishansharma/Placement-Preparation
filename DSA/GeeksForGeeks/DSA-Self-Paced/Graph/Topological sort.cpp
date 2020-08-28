// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

vector <int> topoSort(int N, vector<int> adj[]);

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
bool check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return false;
        }
    }
    return true;
}

// Driver Code
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        vector <int> res = topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
}// } Driver Code Ends


// The Graph structure is as folows

/*  Function which sorts the graph vertices in topological form
*   N: number of vertices
*   adj[]: input graph
*/

// BFS Solution, Kahn;s Algorithm -> 

/*vector<int> topoSort(int V, vector<int> adj[]) 
{
    vector<int> ans;
    
    vector<int> indegree(V, 0);
    
    // Calculate Indegree of Each Vertex
    
    for(int i=0; i<V; i++)
        for(int j=0; j<adj[i].size(); j++)
            indegree[adj[i][j]]++;
            
    queue<int> q;
    
    // Enque each zero degree vertex;
    
    for(int i=0; i<V; i++)
        if(indegree[i] == 0)
            q.push(i);
    
    while(!q.empty())
    {
        int front = q.front();
        q.pop();
        
        // Print front one
        
        ans.push_back(front);
        
        for(int i=0; i<adj[front].size(); i++)
        {
            indegree[adj[front][i]]--; // Reduce indegree dependency
            
            // If dependency becomes 0 then iska time aagaya
            if(indegree[adj[front][i]] == 0)
                q.push(adj[front][i]);
        }
    }
    
    return ans;
}*/

// DFS Based Stack Solution

void DFS(int u, stack<int> &st, vector<bool> &visited, vector<int> adj[], int V)
{
	visited[u] = true;

	for(int i=0; i<adj[u].size(); i++)
	{
		int v = adj[u][i];

		if(!visited[v])
			DFS(v, st, visited, adj, V);
	}

	st.push(u);
}

vector<int> topoSort(int V, vector<int> adj[])
{
	vector<bool> visited(V, false);
	vector<int> ans;
	stack<int> st;

	for(int i=0; i<V; i++)
		if(!visited[i])
			DFS(i, st, visited, adj, V);

	while(!st.empty())
	{
		ans.push_back(st.top());
		st.pop();
	}

	return ans;
}