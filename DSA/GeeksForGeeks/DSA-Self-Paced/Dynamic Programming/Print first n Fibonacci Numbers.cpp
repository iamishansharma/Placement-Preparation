#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

void fib(ll n)
{
    ll fibarr[n+2];
    
    fibarr[0] = 0;
    fibarr[1] = 1;
    
    for(ll i=2; i<=n; i++)
        fibarr[i] = fibarr[i-1] + fibarr[i-2];
        
    for(ll i=1; i<=n; i++)
        cout<<fibarr[i]<<" ";
}

void solve()
{
	ll n=0;
	cin>>n;
	
	fib(n);
	
	cout<<endl;
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