#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

int knapsack01(int n, int w, vector<pair<int,int>> items)
{
    vector<vector<int>> dp(n+1, vector<int> (w+1));
    
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=w; j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(items[i-1].second <= j)
                dp[i][j] = max(items[i-1].first + dp[i-1][j-items[i-1].second], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];    
        }
    }
    
    return dp[n][w];
}

void solve()
{
	int n=0;
	cin>>n;
	
	int w=0;
	cin>>w;
	
	vector<pair<int,int>> items(n);
	
	for(int i=0; i<n; i++)
	    cin>>items[i].first;
    
    for(int i=0; i<n; i++)
	    cin>>items[i].second;
	    
    cout<<knapsack01(n,w,items)<<endl;
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