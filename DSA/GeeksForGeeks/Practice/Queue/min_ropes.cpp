#include <bits/stdc++.h>
using namespace std;
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

void solve()
{
	ll n=0;
	cin>>n;
	
	priority_queue<ll,vector<ll>, greater<ll>> pq;
	
	for(int i=0; i<n; i++)
	{
	    ll temp;
	    cin>>temp;
	    pq.push(temp);
	}
	ll sum = 0;
	while(pq.size() > 1)
	{
	    ll temp1 = pq.top();
	    pq.pop();
	    ll temp2 = pq.top();
	    pq.pop();
	    pq.push(temp1+temp2);
	    sum += temp1+temp2;
	}
	
	cout<<sum<<endl;
}

int main()
{
	int tc=0;
	cin>>tc;
	while(tc--)
	{
		solve();
	}
	return 0;
}