#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n=0,k=0;;
	cin>>n>>k;

	vector<int> v(n);
	
	for(int i=0; i<v.size(); i++)
		cin>>v[i];
	
	vector<int> prev_val;
	prev_val.resize(k+1, -1);

	int output = 0;
	for(int i=0; i<n; i++)
	{
		output = max(output, i - prev_val[v[i]] - 1);
		prev_val[v[i]] = i;
	}
	for(int i=1; i<=k; i++)
		output = max(output, n - 1 - prev_val[i]);

	cout<<output<<endl;
}

int main()
{
	int tc=0;
	cin>>tc;
	while(tc--)
	{
		solve();
	}
	return 0;
}