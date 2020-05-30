#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

void solve()
{
	ll n=0;
	cin>>n;

	string a;
	string b;

	cin>>a;
	cin>>b;

	int i=0;

	vector<vector<int>> ans;

	int flag2 = 0;

	for(int i=0; i<n; i++)
	{
		if(a[i] != b[i])
		{
			int count = 0;

			vector<int> temp;

			for(int j=0; j<n; j++)
			{
				if(b[j] == a[j])
				{
					temp.push_back(j);
					count++;
				}
			}

			if(count == 0)
			{
				flag2 = 1;
				break;
			}
			else
			{
				
			}
		}
		if(flag2 == 1)
			break;
	}

	if(a == b)
	{
		
	}
	
	if(a != b || flag2 == 1)
		cout<<"-1"<<endl;
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