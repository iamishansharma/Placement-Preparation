#include <bits/stdc++.h>
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int
using namespace std;

void dfs(int v,int p,ll *vl,ll *m,ll *ans,ll x,vector<int> adj[])
{
	for(auto i:adj[v])
	{
		if(i!=p)
		{
			dfs(i,v,vl,m,ans,__gcd(x,vl[v]),adj);
		}
	}
	if(adj[v].size() ==1 && v!=1)
	{
		x = __gcd(x,vl[v]);
		ans[v] = m[v] - (__gcd(x,m[v]));
	}
}

void solve()
{
	int n = 0;
	cin>>n;

	vector<int> adj[n+1];

	for(int i=1; i<=n-1; i++)
	{
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	ll vl[n+1],m[n+1];

	for(int i=1;i<=n;i++)
		cin>>vl[i];
	for(int i=1;i<=n;i++)
		cin>>m[i];

	ll ans[n+1];

	memset(ans,-1,sizeof(ans));

	if(n == 1)
		cout<<m[1]-1<<"\n";
	else
	{
		dfs(1,0,vl,m,ans,vl[1],adj);

		for(auto i:ans)
			if(i!=-1)
				cout<<i<<" ";

		cout<<"\n";  
	}
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