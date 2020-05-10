#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;

void solve()
{
	string s;
	cin>>s;

	int count = 0;

	map<string,int> m;
	m.clear();

	for(int i=0; i<s.length()-1; i++)
	{
		if(m[s.substr(i,2)] == 0)
		{
			count++;
			m[s.substr(i,2)]++;
		}
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