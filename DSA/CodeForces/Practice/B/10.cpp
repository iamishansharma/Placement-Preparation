#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long int ll;
using namespace std;

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b)
{
	return a.second > b.second;
}

void solve()
{
	ll n,m;
	cin>>n>>m;

	ll answer = 0;

	vector<pair<ll,ll>> boxes(m);

	for(int i=0; i<m; i++)
	{
		int temp1,temp2;
		cin>>temp1>>temp2;

		boxes[i] = make_pair(temp1,temp2);
	}
	
	sort(boxes.begin(),boxes.end(), sortbysec);

	
	int matches = 0;

	int it = 0;

	while(n > 0 && it < m)
	{
		if(boxes[it].first <= n)
		{
			matches += boxes[it].first * boxes[it].second;
			n -= boxes[it].first;
			it++;
		}
		else
		{
			matches += n * boxes[it].second;
			n -= n;
		}
	}

	cout<<matches;
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