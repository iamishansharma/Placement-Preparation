#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

void solve()
{
	vector<ll> v(5);
	ll p;

	for(int i=0; i<5; i++)
		cin>>v[i];

	cin>>p;

	ll sum = 0;

	for(int i=0; i<5; i++)
	{
		sum += (v[i]*p);
	}

	if(sum > 120)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
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