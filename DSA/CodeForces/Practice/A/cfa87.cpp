#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long int ll;
using namespace std;

void solve()
{
	ll l=0;
	ll r=0;

	cin>>l>>r;

	ll a=l,b=l,c=l;

	if(l % 2 != 0)
		l++;

	if(r-l < 2)
		cout<<"-1";
	else
	{
		cout<<l<<" "<<l+1<<" "<<l+2;
	}
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