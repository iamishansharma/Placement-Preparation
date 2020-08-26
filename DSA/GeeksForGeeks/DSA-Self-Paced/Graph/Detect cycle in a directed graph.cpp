// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/
bool DFS(int start, vector<int> adj[], vector<bool> &visited, vector<bool> &recSt, int V)
{
    visited[start] = true;
    recSt[start] = true;
    
    for(auto i:adj[start])
    {
        if(!visited[i])
        {
            if(DFS(i, adj, visited, recSt, V))
                return true;
        }
        else if(recSt[i] == true)
            return true;
    }
    
    recSt[start] = false;
    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    vector<bool> visited(V, false);
    vector<bool> recSt(V, false);
    
    for(int i=0; i<V; i++)
        if(!visited[i])
            if(DFS(i, adj, visited, recSt, V))
                return true;
    
    return false;
}

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int v, e;
	    cin >> v >> e;
	    
	    vector<int> adj[v];
	    
	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }
	    
	    cout << isCyclic(v, adj) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends