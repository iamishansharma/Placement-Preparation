#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;

void solve()
{
	int n=0,m=0,k=0;
	cin>>n>>m>>k;

	map<pair<int,int>,int> mp;

	int len = k * 4;

	for(int i=0; i<k; i++)
	{
		int r=0, c=0;
		cin>>r>>c;

		mp[{r,c}] = 1;

		if(mp[{r-1,c}] == 1)
			len -= 2;

		if(mp[{r,c-1}] == 1)
			len -= 2;

		if(mp[{r+1,c}] == 1)
			len -= 2;

		if(mp[{r,c+1}] == 1)
			len -= 2;
	}

	cout<<len<<endl;
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