#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

void solve()
{
	int house[2][21]={0};

	int n,p;
	cin>>n>>p;

	int h1,h2,d;

	for(int i=0;i<p;i++)
	{
		cin>>h1>>h2>>d;

		if(house[0][h1])
		{
			if(house[0][house[0][h1]])
			{
				//house 1 diameter
				int d2=house[1][house[0][h1]];
				house[1][h1]=min(house[1][h1],d2);
				house[1][house[0][h1]]=0;
				house[0][i]=house[0][house[0][h1]];
				house[0][house[0][h1]]=0;
			}
		}
		house[0][h1]=h2;
		house[1][h1]=d;
	}
	int change=0;
	do
	{
		change=0;
		for(int i=1;i<=n;i++)
		{
			h2=house[0][i];
			if(h2)
			{
				if(house[0][h2])
				{
					change=1;
					d=house[1][i];//house 1 diameter
					int d2=house[1][h2];
					house[1][i]=min(d,d2);
					house[1][h2]=0;
					house[0][i]=house[0][h2];
					house[0][h2]=0;
				}
			}
		}

	}while(change);

	int count=0;
	
	for(int i=1;i<=n;i++)
		if(house[0][i])
			count++;

	cout<<count<<endl;

	for(int i=1;i<=n;i++)
		if(house[0][i])
			cout<<i<<" "<<house[0][i]<<" "<<house[1][i]<<endl;
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