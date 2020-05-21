#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
typedef long long int ll;
using namespace std;

void solve()
{
	int n,m;
	cin>>n>>m;

	char c;
	cin>>c;

	char room[n][m];

	set<char> adj;

	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin>>room[i][j];

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(room[i][j] == c)
			{
				if(i != 0 && room[i-1][j] != c)
					adj.insert(room[i-1][j]);

				if(i != n-1 && room[i+1][j] != c)
					adj.insert(room[i+1][j]);

				if(j != 0 && room[i][j-1] != c)
					adj.insert(room[i][j-1]);

				if(j != m-1 && room[i][j+1] != c)
					adj.insert(room[i][j+1]);
			}
		}
	}

	int x=0;
 	if(adj.find('.') != adj.end())
    	x--;
  	cout<<adj.size()+x<<endl;
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