#include <bits/stdc++.h>
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int
using namespace std;

void solve()
{
	ll i,n,sum,a[100000];
	cin>>n;
	sum=0;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		sum += a[i];
	}

	sum = sum/(n-1);

	for(i=0;i<n;i++)
		cout<<sum-a[i]<<" ";

	cout<<endl;
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