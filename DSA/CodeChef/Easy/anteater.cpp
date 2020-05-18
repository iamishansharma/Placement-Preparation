#include <bits/stdc++.h>
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int
using namespace std;

void solve()
{
	ll r, c;
	cin>>r>>c;
	vector<vector<char>> grid(r, vector<char>(c, '-'));
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cin>>grid[i][j];
		}
	}
	ll kk=max(r, c);
	ll answer=0;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(grid[i][j]!='#')
			{
				bool left=false, right=false, top=false, bottom=false;
				for(int k=1;k<kk;k++)
				{
					int temp=0;
					if(!top && i-k>=0)
					{
						if(grid[i-k][j]=='D')
						{
							temp++;
						}
						else if(grid[i-k][j]=='#')
						{
							top=true;
						}
					}
					if(!bottom && i+k<r)
					{
						if(grid[i+k][j]=='U')
						{
							temp++;
						}
						else if(grid[i+k][j]=='#')
						{
							bottom=true;
						}
					}
					
					if(!left && j-k>=0){
						if(grid[i][j-k]=='R')
						{
							temp++;
						}
						else if(grid[i][j-k]=='#')
						{
							left=true;
						}
					}
					if(!right && j+k<c)
					{
						if(grid[i][j+k]=='L')
						{
							temp++;
						}
						else if(grid[i][j+k]=='#')
						{
							right=true;
						}
					}
					answer+=(temp*(temp-1))/2;
				}
			}
		}
	}
	cout<<answer<<endl;
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