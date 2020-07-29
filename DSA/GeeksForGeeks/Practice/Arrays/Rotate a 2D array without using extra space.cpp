#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

void solve()
{
	int n=0;
	cin>>n;
	
	vector<vector<int>> mat(n, vector<int> (n));
	
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin>>mat[i][j];

	/*

		1 2 3 
		4 5 6
		7 8 9

		Transpose ->

		1 4 7
		2 5 8
		3 6 9

		Reverse Each Row ->
		7 4 1
		8 5 2
		9 6 3

	*/

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			swap(mat[i][j], mat[j][i]);

	for(int i=0; i<n; i++)
		for(int j=0; j<n/2; j++)
			swap(mat[i][j],mat[i][n-1-j]);

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cout<<mat[i][j]<<" ";
	cout<<endl;
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