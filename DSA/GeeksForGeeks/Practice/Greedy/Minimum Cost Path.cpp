#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

struct cell 
{ 
    int x, y; 
    int distance;
    
    cell(int x, int y, int distance)
    {
        this->x = x;
        this->y = y;
        this->distance = distance;
    } 
};

bool operator<(cell a, cell b)
{
    if (a.distance == b.distance) 
    { 
        if (a.x != b.x) 
            return (a.x < b.x); 
        else
            return (a.y < b.y); 
    } 
    return (a.distance < b.distance);
}

int dijkstra(vector<vector<int>> grid, int n)
{
    vector<vector<int>> dist(n, vector<int> (n));
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            dist[i][j] = INT_MAX;
    
    int dx[] = {-1, 0, 1, 0}; 
    int dy[] = {0, 1, 0, -1};
    
    set<cell> st;
    
    st.insert(cell(0, 0, 0)); 

    dist[0][0] = grid[0][0]; 

    while (!st.empty()) 
    { 
        cell k = *st.begin(); 
        st.erase(st.begin()); 
  
        for (int i = 0; i < 4; i++) 
        { 
            int x = k.x + dx[i]; 
            int y = k.y + dy[i]; 
  
            if (!(x < n && x >= 0 && y < n && y >= 0)) 
                continue; 
 
            if (dist[x][y] > dist[k.x][k.y] + grid[x][y]) 
            { 

                if (dist[x][y] != INT_MAX) 
                    st.erase(st.find(cell(x, y, dist[x][y]))); 
  
                dist[x][y] = dist[k.x][k.y] + grid[x][y]; 
                st.insert(cell(x, y, dist[x][y])); 
            } 
        } 
    } 

    return dist[n - 1][n - 1];
}

void solve()
{
	int n=0;
	cin>>n;
	
	if(n == 1)
	{
	    int ans = 0;
	    cin>>ans;
	    
	    cout<<ans<<endl;
	}
	else
	{
	    vector<vector<int>> grid(n, vector<int> (n));
	
    	for(int i=0; i<n; i++)
    	    for(int j=0; j<n; j++)
    	        cin>>grid[i][j];
    	        
        cout<<dijkstra(grid, n)<<endl;
	}
}

int main()
{
	fastIO;
	
	int tc=0;
	cin>>tc;
	while(tc--)
	{
		solve();
	}
	return 0;
}