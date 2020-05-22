#include <bits/stdc++.h>
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int
using namespace std;

void solve()
{
	int k=0;
	int q=0;
	cin>>k>>q;

	vector<ll> a(k);
	
	for(int i=0; i<a.size(); i++)
		cin>>a[i];

	vector<ll> b(k);
	
	for(int i=0; i<b.size(); i++)
		cin>>b[i];

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	vector<ll> sums;

	if(k <= 100)
		for (size_t i = 0; i < k; i++)
			for (size_t j = 0; j < k; j++)
				sums.push_back(a[i] + b[j]);
	else
	{
		ll maxval = a[100] + b[100];

		for(size_t i = 0; i < k; i++)
			for (size_t j  = 0; j < k && a[i]+b[j] < maxval; j++)
				sums.push_back(a[i] + b[j]);
	}

	sort(sums.begin(),sums.end());

	while(q--)
	{
		int qi = 0;
		cin>>qi;

		cout<<sums[qi-1]<<endl;
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