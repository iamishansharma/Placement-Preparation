#include <bits/stdc++.h>
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int
using namespace std;

void solve()
{
	int n=0;
	cin>>n;

	vector<int> v(n);
	
	for(int i=0; i<v.size(); i++)
		cin>>v[i];

	vector<int> ans;

	ans.push_back(v[0]);
	
	for(int i=1; i<v.size(); i++)
	{
		if(upper_bound(ans.begin(),ans.end(),v[i])-ans.begin() >= ans.size())
			ans.push_back(v[i]);
		else
			ans[upper_bound(ans.begin(),ans.end(),v[i])- ans.begin()] = v[i];
	}

	cout<<ans.size()<<" ";

	for(auto itr2 = ans.begin(); itr2 != ans.end(); itr2++)
	{
		cout<<*itr2<<" ";
	}
	cout<<endl;
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