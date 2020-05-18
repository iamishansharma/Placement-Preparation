#include <bits/stdc++.h>
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int
using namespace std;

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b) 
{ 
	return (a.second > b.second); 
} 

void solve()
{
	int n=0,m=0;
	cin>>n>>m;

	vector<pair<int,int>> dish(n);

	for(int i=0; i<n; i++)
	{
		int temp1,temp2;
		cin>>temp1>>temp2;

		dish[i] = make_pair(temp1,temp2);
	}

	sort(dish.begin(), dish.end(), sortbysec);

	int i=0; 
	int j=1;

	while(dish[i].first == dish[j].first)
		j++;

	cout<<dish[i].second+dish[j].second<<endl;
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