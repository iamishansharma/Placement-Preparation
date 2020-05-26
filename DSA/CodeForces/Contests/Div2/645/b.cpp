#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

void solve()
{
	ll n=0;
	cin>>n;

	vector<ll> v(n);
	
	for(int i=0; i<v.size(); i++)
		cin>>v[i];
	
	sort(v.begin(),v.end());

	if(v[0] != 1)
	{
		cout<<"1"<<endl;
	}
	else
	{
		ll count = 0;

		int flag = 0;

		for(int i=0; i<n; i++)
		{
			count = 1 + (i+1);
			cout<< "Count: " << count << " V: " << v[i] <<endl;
			if(count >= v[i])
			{
				continue;
			}
			else
			{
				flag = 1;
				break;
			}
		}

		if(flag == 1)
			cout<< count-1 <<endl;
		else
			cout<< count << endl;
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