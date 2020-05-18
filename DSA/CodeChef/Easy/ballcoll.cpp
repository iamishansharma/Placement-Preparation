#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long int ll;
using namespace std;

void solve()
{
	int n, m, x, u, i, ans=0;

	cin>>n>>m;

	map<int,int> M;

	for(i=0; i<n; i++)
	{
		cin>>x>>u;
		M[x*u]++;
	}
	for(i=0; i<m; i++)
	{
		cin>>x>>u;

		if(M[x*u])
		{
			M[x*u]--;
			ans++;
		}
	}
	cout<<ans;
}

int main()
{
	fastIO;

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin); 
		freopen("output.txt", "w", stdout); 
	#endif
	
	solve();
	
	return 0;
}