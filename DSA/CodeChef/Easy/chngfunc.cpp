#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long int ll;
using namespace std;

void solve()
{
	ll a=0,b=0;
	cin>>a>>b;

	ll count = 0;

	for(ll x = 1; x <= a; x++) 
	{
		for(ll z = x; ; z++) 
		{
			long long y = z*z - x*x;

			if(y > b)
			{
				break;
			}
			if(y >= 1 && y <= b) 
			{
				count++;
			}
		}
	}

	cout<<count<<endl;
}

int main()
{
	fastIO;
	solve();
	return 0;
}