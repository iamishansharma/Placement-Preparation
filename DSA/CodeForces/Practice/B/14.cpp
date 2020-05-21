#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long int ll;
using namespace std;

void solve()
{
	int n=0;
	cin>>n;

	vector<int> a(n);
	map<int,int> m;
	m.clear();
	
	for(int i=0; i<a.size(); i++)
	{
		cin>>a[i];
		m[a[i]] = i+1;
	}
	
	int mi=0;
	cin>>mi;

	vector<int> b(mi);

	ll v=0;
	ll p=0;
	
	for(int i=0; i<b.size(); i++)
	{
		cin>>b[i];

		v += (m[b[i]]);
		p += (n-m[b[i]]+1);
	}
	
	cout<<v<<" "<<p;
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