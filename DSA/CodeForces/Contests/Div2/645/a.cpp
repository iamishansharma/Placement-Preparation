#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

void solve()
{
	int n,m;
	cin>>n>>m;

	if(n == 1 && m == 1)
		cout<<"1"<<endl;
	else
	{
		if(n == 1 && m != 1)
		{
			cout<< ceil((double)m/2) << endl;
		}
		else if(m == 1 && n != 1)
		{
			cout<< ceil((double)n/2) << endl;
		}
		else if(n != 1 && m != 1)
		{
			int maxval = max(n,m);
			int minval = min(n,m);

			if(maxval % 2 == 0)
				cout<< (maxval/2) * minval << endl;
			else
			{
				cout << ((maxval/2) * (minval)) + (ceil((double)minval/2)) << endl;
			}
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