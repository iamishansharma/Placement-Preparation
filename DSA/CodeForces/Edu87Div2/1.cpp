#include <bits/stdc++.h>
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int
using namespace std;

void solve()
{
	ll a,b,c,d;
	cin>>a>>b>>c>>d;

	if(b >= a)
		cout<<b<<endl;
	else
	{
		if(d >= c)
			cout<<"-1"<<endl;
		else
		{
			ll tt = b;
		
			ll left = a-b;

			tt += ceil((long double)left/(long double)(c-d))*c;

			cout<<tt<<endl;
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