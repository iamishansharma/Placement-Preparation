#include <bits/stdc++.h>
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int
using namespace std;

vector<int> leftshift(vector<int> a, int d)
{
	vector<int> ret(a.size());

	for(int i=0; i<a.size(); i++)
	{
		int index = i-d;

		if(index < 0)
			ret[a.size()-abs(index)] = a[i];
		else
			ret[i-d] = a[i];
	}
	return ret;
}

vector<int> rightshift(vector<int> a, int d)
{
	vector<int> ret(a.size());

	for(int i=0; i<a.size(); i++)
	{
		int index = i+d;

		if(index > a.size()-1)
			ret[index - a.size()] = a[i];
		else
			ret[i+d] = a[i];
	}
	return ret;
}

void solve()
{
	int k=0;
	cin>>k;

	if(k == 1)
		cout<<"1"<<endl;
	else
	{
		vector<vector<int>> ans(k, vector<int> (k));
		vector<int> tempup(k);
		vector<int> tempdown(k);

		for(int i=0; i<k; i++)
		{
			ans[(k+1)/2-1][i] = i+1;
			tempup[i] = i+1;
			tempdown[i] = i+1;
		}

		for(int i = (k+1)/2; i<k; i++)
		{
			tempdown = leftshift(tempdown, 1);
			ans[i] = tempdown;
		}

		for(int i = (k+1)/2-2; i>=0; i--)
		{
			tempup = rightshift(tempup, 1);
			ans[i] = tempup;
		}

		for(int i=0; i<k; i++)
		{
			for(int j=0; j<k; j++)
				cout<<ans[i][j]<<" ";
			cout<<endl;
		}
	}
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