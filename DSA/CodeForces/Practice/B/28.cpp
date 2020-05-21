#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
typedef long long int ll;
using namespace std;

void solve()
{
	ll n=0;
	cin>>n;

	vector<ll> v1(n);
	vector<ll> v2(n);
	
	for(int i=0; i<v1.size(); i++)
	{
		cin>>v1[i];
		v2[i] = v1[i];
	}

	sort(v2.begin(), v2.end());

	for(int i=1; i<n; i++)
	{
		v1[i] += v1[i-1];
		v2[i] += v2[i-1];
	}

	/*for(int i=0; i<n; i++)
	{
		debug(v1[i]);
	}
	
	for(int i=0; i<n; i++)
	{
		debug(v2[i]);
	}*/

	ll m=0;
	cin>>m;

	while(m--)
	{
		ll type, l , r;
		cin>>type>>l>>r;

		if(type == 1)
			cout<<v1[r]-v1[l-1]<<endl;
		else
			cout<<v2[r]-v1[l-1]<<endl;
	}
}

int main()
{
	fastIO;

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin); 
		freopen("output.txt", "w", stdout); 
	#endif
	
	solve();
}