#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

void solve()
{
	ll a,b;
	cin>>a>>b;

	if(a == b)
		cout<< 2 * a * 2 * a <<endl;

	else if(a / b == 2 && a != b)
		cout<<a*a<<endl;
	else if(b / a == 2 && a != b)
		cout<<b*b<<endl;
	else
	{
		int maxval = max(a,b);
		cout<<(maxval+1)*(maxval+1)<<endl;
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