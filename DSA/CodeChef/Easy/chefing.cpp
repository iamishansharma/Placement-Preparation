#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;

void solve()
{
	int n;
	cin>>n;

	set<char> s;

	map<char,int> m;
	m.clear();
	
	for(int i=0; i<n; i++)
	{
		s.clear();

		string str;

		cin>>str;

		for(int j=0; j<str.length(); j++)
			s.insert(str[j]);

		for(auto it=s.begin(); it!=s.end(); it++)
			m[*it]++;
	}

	int answer = 0;

	for(auto const& pair:m)
	{
		if(pair.second == n)
			answer++;
	}

	cout<<answer<<endl;
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