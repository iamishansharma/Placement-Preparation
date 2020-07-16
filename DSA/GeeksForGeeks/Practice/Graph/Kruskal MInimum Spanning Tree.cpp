// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int spanningTree(int V, int E, vector<vector<int>> &graph);
// Driver code

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int> > graph(V, vector<int>(V, INT_MAX));
        int i=0;
        while (i++<E) {
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
bool cmp(pair<int,pair<int,int>> g1, pair<int,pair<int,int>> g2)
{
    return g1.first < g2.first;
}

int Find(int i,int parent[])
{
    if(parent[i] == -1)
    return i;
    
    return Find(parent[i],parent);
}

void Union(int i,int j, int parent[],int n)
{
    int pI = Find(i,parent);
    int pJ = Find(j,parent);
    
    int temp = pJ;
    parent[pJ] = pI;
    
    for(int k=0; k<n; k++)
        if(parent[k] == temp)
            parent[k] = pI;

}

int spanningTree(int V, int E, vector<vector<int>> &graph) 
{   
    // Kruskals -> 
    
    vector<pair<int,pair<int,int>>> v;
    
    for(int i=0; i<V; i++)
        for(int j=i+1; j<V; j++)
            if(graph[i][j] != INT_MAX)
                v.push_back(make_pair(graph[i][j],make_pair(i,j)));
    
    int n = v.size();
    sort(v.begin(), v.end(), cmp);
    
    int parent[V];
    memset(parent,-1,sizeof(parent));
    
    int edge = 1;
    int i = 0;
    int ans = 0;
    
    while(edge <= V-1)
    {
        if(Find(v[i].second.first, parent) != Find(v[i].second.second, parent))
        {
            ans += v[i].first;
            Union(v[i].second.first, v[i].second.second, parent, V);
            edge++;
        }
        i++;
    }
    
    return ans;
}