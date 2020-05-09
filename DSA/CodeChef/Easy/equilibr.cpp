#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define mod 1000000007
using namespace std;

inline ll vec(ll x,ll p)
{
	ll ret=1;
	while(p)
	{
		if(p&1)
			ret=ret*x%mod;
		x=x*x%mod;
		p>>=1;
	}
	return ret;
}
int main()
{
	ll n,k;
	cin>>n>>k;
	cout<<(vec(2,n-1)-n+mod)%mod*vec(2,(n-1)*(mod-2))%mod;
	return 0;
}