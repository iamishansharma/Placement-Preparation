// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends


/*
 * Function to find if there is a mother vertex in the given graph 
 * V: number of vertices in the graph
 * g[]: graph representation
 */

void DFS(int src, vector<bool> &visited, vector<int> g[])
{
    visited[src] = true;
    
    for(int uv : g[src])
        if(!visited[uv])
            DFS(uv, visited, g);
}

int findMother(int V, vector<int> g[]) 
{ 
    vector<bool> visited(V, false);
    
    int mother = -1;
    
    for(int i=0; i<V; i++)
        if(!visited[i])
        {
            DFS(i, visited, g);
            mother = i;
        }
        
    for(int i=0; i<V; i++)
        visited[i] = false;
    
    DFS(mother, visited, g);
    
    for(int i=0; i<V; i++)
        if(!visited[i])
            return -1;
    
    return mother;
} 

// { Driver Code Starts.

int main() 
{ 
    int T;
    cin>>T;
    while(T--){
        int num, edges;
        cin>>num>>edges;
        
        vector<int> adj[num];
        
        int u, v;
        while(edges--){
            cin>>u>>v;
            adj[u].push_back(v);
        }
        
        cout<<findMother(num, adj)<<endl;
    }

	return 0;
}   // } Driver Code Ends