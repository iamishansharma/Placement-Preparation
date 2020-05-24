#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

void solve()
{
	ll n=0;
	cin>>n;

	vector<ll> v(n);
		
	for(int i=0; i<v.size(); i++)
		cin>>v[i];

	if(n == 1)
		cout<<"1"<<endl;
	else
	{
		vector<ll> pre(n*(n+1)/2);

		for(int i=0; i<n; i++)
		{
			
		}
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