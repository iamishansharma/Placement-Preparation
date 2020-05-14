#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long int ll;
using namespace std;

void solve()
{
	int n=0;
	cin>>n;

	vector<pair<int,pair<int,int>>> v(n);

	for(int i=0; i<n; i++)
		cin>>v[i].first>>v[i].second.first>>v[i].second.second;

	int answer = 0;

	answer += v[0].first + v[0].second.first;

	int currtime = v[0].first + v[0].second.first;

	int i=1;

	while(i <= n-1)
	{
		//cout<<"V: ("<<v[i].first<<", "<<v[i].second.first<<", "<<v[i].second.second<<")"<<" CurrTime: "<<currtime<<" Answer: "<<answer<<endl;
		if(currtime < v[i].first)
		{
			answer += (v[i].first - currtime) + v[i].second.first;
			currtime = answer;
			i++;
		}
		else
		{
			int near = v[i].first;

			while(near < currtime)
				near += v[i].second.second;

			answer += near - currtime + v[i].second.first;

			currtime = answer;

			i++;
		}
	}

	cout<<answer<<endl;
}

int main()
{
	fastIO;

	/*#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif*/
	
	int tc=0;
	cin>>tc;
	while(tc--)
	{
		solve();
	}
	return 0;
}