bool iscycle(int src, vector<vector<int>> &adj, vector<bool> &visited,int parent) 
{
    visited[src] = true;
    
    for (auto i : adj[src]) 
    {
        if(i!=parent)
        {
            if(visited[i])
            {
                return true;
            }
            if(!visited[i] and iscycle(i,adj,visited,src))
               return true;
        }
    }
    
    return false;
}

int Solution::solve(int n, vector<vector<int> > &a) 
{
    vector<vector<int>> adj(n);
    
    for (auto e : a) 
    {
        adj[e[0] - 1].push_back(e[1] - 1);
        adj[e[1] - 1].push_back(e[0] - 1);
    }
    
    vector<bool> visited(n, false);
    
    for (int i = 0; i < n; i++) 
    {
        if(!visited[i] and iscycle(i, adj, visited,-1))
           return true; 
    }
    return false;
}