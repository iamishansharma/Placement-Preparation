#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;

void solve()
{
	int n=0;
	cin>>n;

	vector<int> per(n);

	for(int i=0; i<n; i++)
		per[i] = i+1;

	int swap = 0;

	if(n % 2 == 0)
	{
		for(int i=0; i<=n-2; i=i+2)
		{
			swap = per[i];
			per[i] = per[i+1];
			per[i+1] = swap;
		}
	}
	else
	{
		int i=0;
		for(i=0; i<=n-4; i=i+2)
		{
			swap = per[i];
			per[i] = per[i+1];
			per[i+1] = swap;
		}

		int swap2 = per[i];

		per[i] = per[i+1];
		per[i+1] = per[i+2];
		per[i+2] = swap2;
	}

	for(int i=0; i<n; i++)
	{
		cout<<per[i]<<" ";
	}
}

int main()
{
	fastIO;
	int tc=0;
	cin>>tc;
	while(tc--)
	{
		solve();
	}
	return 0;
}