#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;

void solve()
{
	int n=0,k=0;

	cin>>n>>k;

	vector<int> v(n);
	
	for(int i=0; i<v.size(); i++)
		cin>>v[i];
	
	int sum = 0;

	for(int i=0; i<v.size(); i++)
		sum += v[i];

	int count = 0;

	for(int i=0; i<v.size(); i++)
	{
		if(v[i]+k > sum-v[i])
			count++;
	}

	cout<<count<<endl;
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