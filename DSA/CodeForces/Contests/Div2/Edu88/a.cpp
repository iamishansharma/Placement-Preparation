#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

void solve()
{
	ll n,m,k;
	cin>>n>>m>>k;

	if(m == 0)
		cout<< "0" <<endl;
	else
	{
		ll card = n/k;

		if(card >= m)
			cout<< m <<endl;
		else
		{
			if(k-1 >= m - card)
				cout<< card-1 <<endl;
			else
				cout<< card - (ceil((double)(m-card)/(double)(k-1))) << endl;
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