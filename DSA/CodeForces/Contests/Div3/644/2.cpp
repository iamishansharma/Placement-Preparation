#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int


void solve()
{
	int n = 0;
	cin>>n;

	vector<int> v(n);
	
	for(int i=0; i<v.size(); i++)
		cin>>v[i];
	
	sort(v.begin(), v.end());

	vector<int> ans(n);

	ans[0] = INT_MAX;

	for(int i=1; i<n; i++)
	{
		ans[i] = v[i] - v[i-1];
	}

	cout<<*min_element(ans.begin(), ans.end())<<endl;
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