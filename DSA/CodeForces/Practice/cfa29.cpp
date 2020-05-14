#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long int ll;
using namespace std;

void solve()
{
	int n=0;
	cin>>n;

	int teams[n][2];

	for(int i=0; i<n; i++)
		for(int j=0; j<2; j++)
			teams[i][j] = -1;

	for(int i=0; i<n; i++)
		for(int j=0; j<2; j++)
			cin>>teams[i][j];

	map<int,int> g;
	g.clear();

	for(int i=0; i<n; i++)
		g[teams[i][1]]++;

	int answer = 0;

	for(int i=0; i<n; i++)
		answer += g[teams[i][0]];

	cout<<answer<<endl;
}

int main()
{
	fastIO;

	/*#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif*/
	
	solve();
}