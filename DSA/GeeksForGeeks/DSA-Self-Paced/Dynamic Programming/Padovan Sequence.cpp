#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

ll padovan(ll n)
{
    ll pad[n+3];
    
    pad[0] = 1;
    pad[1] = 1;
    pad[2] = 1;
    
    for(int i=3; i<=n; i++)
        pad[i] = (pad[i-2] + pad[i-3])%1000000007;
    
    return pad[n];
}

void solve()
{
	ll n=0;
	cin>>n;
	
	cout<<padovan(n)<<endl;
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