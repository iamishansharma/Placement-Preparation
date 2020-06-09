// https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room/0

#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

bool comp(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b)
{
	return a.first.second < b.first.second;
}

void solve()
{
	int n=0;
	cin>>n;
	
	vector<int> s(n);
	
	for(int i=0; i<s.size(); i++)
		cin>>s[i];

	vector<int> f(n);
	
	for(int i=0; i<f.size(); i++)
		cin>>f[i];
	
	vector<pair<pair<int,int>,int>> meet(n);

	for(int i=0; i<n; i++)
		meet[i] = make_pair(make_pair(s[i],f[i]),i);

	sort(meet.begin(), meet.end(), comp);

	vector<int> ans;

	ans.push_back(meet[0].second + 1);

	int ft = meet[0].first.second;

	for(int i=1; i<n; i++)
	{
		if(meet[i].first.first >= ft)
		{
			ans.push_back(meet[i].second + 1);
			ft = meet[i].first.second;
		}
	}

	for(auto i:ans)
		cout<<i<<" ";

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