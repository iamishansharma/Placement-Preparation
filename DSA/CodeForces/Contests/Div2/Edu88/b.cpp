#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

void solve()
{
	int n,m,x,y;
	cin>>n>>m>>x>>y;

	char mat[n+1][m+1];

	unordered_map<char,int> m;

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			cin>>mat[i][j];
			m[mat[i][j]]++;
		}
	}

	ll cost1 = m['.'] * x;

	
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