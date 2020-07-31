#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

void solve()
{
	ll n=0;
	cin>>n;
	
	vector<ll> arr(n);
	
	for(int i=0; i<n; i++)
	    cin>>arr[i];
	
	ll twice = 0;
	ll miss = 0;
	
	ll realsum = (n * (n+1))/2;
	ll realsumsq = (n * (n+1) * (2*n + 1))/6;
	
	ll sum = 0;
	ll sumsq = 0;
	
	for(int i=0; i<n; i++)
	{
	    sum += arr[i];
	    sumsq += arr[i]*arr[i];
	}
	
	ll sumdiff = sum - realsum;
	ll sumsqdiff = sumsq - realsumsq;
	
	twice = (sumdiff + (sumsqdiff)/(sumdiff))/2;
	miss = twice - sumdiff;
	
	cout<<twice<<" "<<miss<<endl;
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