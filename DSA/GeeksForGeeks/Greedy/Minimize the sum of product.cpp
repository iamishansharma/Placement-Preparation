#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

bool comp(ll a, ll b)
{
	return a > b;
}

void solve()
{
	ll n=0;
	cin>>n;

	vector<ll> a(n);
	
	for(ll i=0; i<a.size(); i++)
		cin>>a[i];
	
	vector<ll> b(n);
	
	for(ll i=0; i<b.size(); i++)
		cin>>b[i];

	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), comp);
	
	ll sum = 0;

	for(ll i=0; i<n; i++)
		sum += a[i]*b[i];

	cout<<sum<<endl;
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