#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long int ll;
using namespace std;

void solve()
{
	string s;
	cin>>s;

	vector<int> v;

	int i=0;

	while(i < s.length())
	{
		int count = 0;

		int j=i;

		while(s[j] != '#')
		{
			count++;
			j++;
		}

		if(count!=0)
			v.push_back(count+1);

		i=j+1;
	}

	ll answer = 0;

	ll max = LLONG_MIN;

	for(int i=0; i<v.size(); i++)
	{
		if(v[i] > max)
		{
			max = v[i];
			answer++;
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