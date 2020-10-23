// { Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends





//User function Template for C++


/**
 *  ith value in adj vector contains information between the node connected to it and weight between them.
 *  Example. for a value 2 3 1, Node 2 and Node 3 has weight 1. adj[2] = {3,1} and adj[3] = {2,1}.
 *  n -> number of nodes
 *  m -> total number of edges
 *  return the mst value
*/
int findparent(int node, int parent[])
{
    if(node == parent[node])
        return node;
    return parent[node] = findparent(parent[node],parent);
}

bool union_( int a, int b, int parent[], int rank[]) 
{
    int x = findparent(a, parent);
    int y = findparent(b, parent);
    
    if(x == y) 
        return true;
    else
    {
        if(rank[x] >= rank[y])
        {
            rank[x]++;
            parent[y] = parent[x];
        } 
        else
        {
            rank[y]++;
            parent[x] = parent[y];
        }
        return false;
    }
}

long long int kruskalDSU(vector<pair<int, long long int>> adj[], int n, int m) 
{

    pair<long long int, pair<int,int>> weight[2*m];

    int parent[n+1], rank[n+1];
    
    for(int i = 1; i <= n; i++)
    {
        parent[i] = i;
        rank[i] = 1;
    }

    int tot=0;


    for(int i=1; i <= n; i++) 
    {
        for(int j=0; j < adj[i].size(); j++) 
        { 
            weight[tot++] = {adj[i][j].second, {i, adj[i][j].first}}; 
        }
    }
    
    sort(weight, weight + tot);
    
    long long mst = 0;
    
    for(int i=0; i<tot; i++) 
    { 
        int u = weight[i].second.first; 
        int v = weight[i].second.second; 
        long long w = weight[i].first;
        
        if(!union_(u, v, parent, rank)) 
        {
            mst += w; 
        } 
    } 
    return mst; 
}


// { Driver Code Starts.

int main() {
    int t;
    cin>>t;

    vector<pair<int, long long int>> adj[100009];

    while(t--) {

        int n,m;
        cin>>n>>m;

        int u,v;
        long long w;
        for(int i=0; i<m; i++) {
            cin>>u>>v>>w;
            adj[u].push_back(make_pair(v,w));
            adj[v].push_back(make_pair(u,w));
        }

        cout<<kruskalDSU(adj, n, m)<<endl;

        for(int i=0; i<=n; i++) {
            adj[i].clear();
        }
    }
    return 0;
}
  // } Driver Code Ends