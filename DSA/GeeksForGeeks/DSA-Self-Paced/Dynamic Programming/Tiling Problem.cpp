#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

void solve()
{
	int w=0;
	cin>>w;
	
	vector<ll> tile(w+1);
	
	tile[0] = 1;
	tile[1] = 1;
	
	for(int i=2; i<=w; i++)
	    tile[i] = tile[i-1] + tile[i-2];
	    
	cout<<tile[w]<<endl;
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