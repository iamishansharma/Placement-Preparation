#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long int ll;
using namespace std;

void solve()
{
	ll n=0;

	cin>>n;

	vector<ll> v(n);
	
	for(int i=0; i<v.size(); i++)
		cin>>v[i];
	
	vector<pair<ll,ll>> answer(n);

	for(int i=0; i<n; i++)
	{
		if(v[i] % 2 == 0)
			answer[i] = make_pair(v[i]/2,0);
		else
			answer[i] = make_pair(floor((double)v[i]/(double)2),1);
	}

	ll sum = 0;

	for(int i=0; i<n; i++)
		sum += answer[i].first;

	if(sum < 0)
	{
		int change = abs(sum);

		for(int i=0; i<n && change > 0; i++)
		{
			if(answer[i].second == 1)
			{
				change--;
				answer[i].first++;
			}
		}

		for(int i=0; i<n; i++)
			cout<<answer[i].first<<endl;
	}
	else if(sum > 0)
	{
		int change = abs(sum);

		for(int i=0; i<n && change > 0; i++)
		{
			if(answer[i].second == 1)
			{
				change--;
				answer[i].first--;
			}
		}

		for(int i=0; i<n; i++)
			cout<<answer[i].first<<endl;
	}
	else
	{
		for(int i=0; i<n; i++)
			cout<<answer[i].first<<endl;
	}
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