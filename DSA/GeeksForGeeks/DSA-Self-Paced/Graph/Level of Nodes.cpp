// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    vector<int> *adj;

public:
    Graph(int V);
    void addEdge(int u, int v);
    int levels(int x, int in);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new vector<int>[V + 1];
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// } Driver Code Ends

// The Graph structure is as folows
/*
class Graph 
{ 
	int V; 
	vector<int> *adj; 
    
public: 
    Graph(int V); 
	void addEdge(int u, int v); 
	int countPaths(int s, int d); 
}; 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new vector<int>[V+1]; 
} 

void Graph::addEdge(int u, int v) 
{ 
    adj[u].push_back(v); 
} 
*/

// Complete the Function
int Graph::levels(int start, int required)
{
    bool visited[V + 1] = {false};

    queue<pair<int, int>> q;

    q.push({start, 0});
    visited[0] = true;

    while (q.empty() == false)
    {
        auto curr = q.front();
        q.pop();

        if (curr.first == required)
            return curr.second;

        int u = curr.first;
        int level = curr.second;

        for (int v : adj[u])
        {
            if (!visited[v])
            {
                q.push({v, level + 1});
                visited[v] = true;
            }
        }
    }

    return -1;
}

// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;

    while (t--)
    {

        int n, e;
        cin >> n >> e;
        Graph g(n);
        int u, v;
        for (int i = 0; i < e; i++)
        {
            cin >> u >> v;
            g.addEdge(u, v);
        }

        int x;
        cin >> x;

        if (x >= n)
            cout << "-1" << endl;
        else
            cout << g.levels(0, x) << endl;
    }

    return 0;
}
// } Driver Code Ends