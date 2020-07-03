#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

int goldmine(vector<vector<int>> mat, int n, int m)
{
    vector<vector<int>> dp(n, vector<int> (m));
    
    // DP tabulization here
    
    for(int col = m-1; col>=0; col--)
    {
        for(int row = 0; row < n; row++)
        {
            int right = (col == m-1) ? 0 : dp[row][col+1];
            int right_up = (row == 0 || col == m-1) ? 0 : dp[row-1][col+1];
            int right_down = (row == n-1 || col == m-1) ? 0 : dp[row+1][col+1];
            
            dp[row][col] = mat[row][col] + max(right, max(right_up,right_down));
        }
    }
    
    // Now get maxv value from coloumn 1 and all rows
    int maxval = INT_MIN;
    
    for(int i=0; i<n; i++)
        maxval = max(maxval, dp[i][0]);
    
    return maxval;
}

void solve()
{
	int n=0;
	cin>>n;
	
	int m=0;
	cin>>m;
	
	vector<vector<int>> mat(n, vector<int> (m));
	
	for(int i=0; i<n; i++)
	    for(int j=0; j<m; j++)
	        cin>>mat[i][j];
	
	cout<<goldmine(mat,n,m)<<endl;
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