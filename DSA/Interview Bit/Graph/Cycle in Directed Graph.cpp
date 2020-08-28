bool DFS(int start, vector<bool> &visited, vector<bool> &recSt, vector<int> adj[])
{
    visited[start] = true;
    recSt[start] = true;
    
    for(int i=0; i<adj[start].size(); i++)
    {
        int u = adj[start][i];
        
        if(!visited[u] && DFS(u, visited, recSt, adj))
            return true;
        else if(recSt[u] == true)
            return true;
    }
    
    recSt[start] = false;
    return false;
}

int Solution::solve(int V, vector<vector<int>> &mat) 
{
    vector<int> adj[V];
    
    for(int i=0; i<mat.size(); i++)
        adj[mat[i][0]-1].push_back(mat[i][1]-1);
        
    vector<bool> visited(V,false);
    vector<bool> recSt(V,false);
    
    for(int i=0; i<V; i++)
        if(!visited[i])
            if(DFS(i, visited, recSt, adj))
                return true;
    
    return false;
}
