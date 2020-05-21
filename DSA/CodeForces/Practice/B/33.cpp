#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
typedef long long int ll;
using namespace std;

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b)
{
	return a.second > b.second;
}

void solve()
{
	ll n,f;
	cin>>n>>f;

	vector<pair<ll,ll>> a;
	ll k[n];
	ll l[n];

	for (int i = 0; i < n; i++) 
	{
	    cin >> k[i] >> l[i];
	    a.push_back(make_pair(min(2 * k[i], l[i]) - min(k[i], l[i]), i));
	}

	sort(a.rbegin(), a.rend());

	long long ans = 0;

	for (int i = 0; i < f; i++) 
	{
	    int pos = a[i].second;
	    ans += min(2 * k[pos], l[pos]);
	}
	for (int i = f; i < n; i++) 
	{
	    int pos = a[i].second;
	    ans += min(k[pos], l[pos]);
	}
	cout << ans;
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