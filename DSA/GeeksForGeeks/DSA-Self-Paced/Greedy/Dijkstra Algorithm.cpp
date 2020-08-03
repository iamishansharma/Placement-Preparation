// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

vector <int> dijkstra(vector<vector<int>> , int ,int );

int printSolution(vector <int> dist, int n)
{
  
   for (int i = 0; i < n; i++)
      printf("%d ", dist[i]);
  
}
int main()
{
    int t;
    int V;
    cin>>t;
    while(t--){
        cin>>V;
        
        vector<vector<int>> g(V);
        
        for(int i = 0;i<V;i++){
            vector<int> temp(V);
            g[i] = temp;
        }
        
        for(int i=0;i<V;i++)
        {
      	    for(int j=0;j<V;j++)
      	    {
      		    cin>>g[i][j];
      	    }
        }
        
        int s;
        cin>>s;
        
        vector <int> res = dijkstra(g, s, V);
        printSolution (res, V);
        cout<<endl;
       }
        return 0;
}// } Driver Code Ends


/*  Function to implement Dijkstra
*   g: vector of vectors which represents the graph
*   src: source vertex to start traversing graph with
*   V: number of vertices
*/

vector<int> dijkstra(vector<vector<int>> g, int src, int V)
{
    priority_queue<pair<int, int>, vector <pair<int, int>> , greater<pair<int,int>>> pq;
    
    vector<int> dist(V, INT_MAX);
    
    pq.push(make_pair(0,src));
    dist[src] = 0;
    
    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        
        for(int i=0; i<V; i++)
        {
            if(g[u][i] != 0)
            {
                if(dist[u] + g[u][i] < dist[i])
                {
                    dist[i] = dist[u] + g[u][i];
                    pq.push(make_pair(dist[i], i));
                }
            }
        }
    }
    
    return dist;
}