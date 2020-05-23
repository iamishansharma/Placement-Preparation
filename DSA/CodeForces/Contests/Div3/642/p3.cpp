#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long int ll;
using namespace std;

void solve()
{
	ll n=0;
	ll m=0;

	cin>>n>>m;

	if(n == 1)
		cout<<"0"<<endl;
	else if(n == 2)
		cout<<m<<endl;
	else
	{
		cout<<2*m<<endl;
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