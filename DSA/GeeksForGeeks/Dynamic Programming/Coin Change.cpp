#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

int CoinChange(vector<int> coins, int n, int value)
{
    vector<vector<int>> dp(n+1, vector<int> (value+1));
    
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=value; j++)
        {
            if(i==0 && j==0)
                dp[i][j] = 1;
            else if(j == 0)
                dp[i][j] = 1;
            else if(i == 0)
                dp[i][j] = 0;
            else if(coins[i] <= j)
                dp[i][j] = dp[i-1][j] + dp[i][j-coins[i]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][value];
}

void solve()
{
	int n=0;
	cin>>n;
	
	vector<int> coins(n+1);
	
	coins[0] = 0;
	
	for(int i=0; i<n; i++)
	    cin>>coins[i+1];
	    
	int value = 0;
    cin>>value;
    
    cout<<CoinChange(coins, n, value)<<endl;
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