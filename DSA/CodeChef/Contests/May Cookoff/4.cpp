#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

void solve()
{
	ll n=0;
	cin>>n;

	int grid[n+1][n+1];

	for(ll i=1; i<=n; i++)
	{
		for(ll j=1; j<=i; j++)
		{
			if(i>j)
			{
				if(i == j)
					grid[i][j] = 0;
				else
					grid[i][j] = i & j;
			}
			else
			{
				grid[i][j] = 0;
			}
		}
	}

	ll sum = 0;

	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(i>j)
			{
				sum += grid[i][j];
				cout<<grid[i][j]<<" ";
			}
		}
		cout<<endl;
	}

	cout<<endl;

	if(sum == 0)
		cout<<"-1"<<endl;
	else
		cout<<sum<<endl;
}

int main()
{
	fastIO;

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin); 
		freopen("output.txt", "w", stdout); 
	#endif
	
	int tc=0;
	cin>>tc;
	while(tc--)
	{
		solve();
	}
	return 0;
}