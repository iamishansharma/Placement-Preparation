#include <bits/stdc++.h>
using namespace std;

int main()
{
	int tc=0;
	cin>>tc;
	while(tc--)
	{
		int n=0, q=0;
		cin>>n>>q;
		string s;
		cin>>s;

		map<char,int> pat;
		pat.clear();
		for(int i=0; i<s.length(); i++)
			pat[s[i]] += 1;
		
		for(int i=0; i<q; i++)
		{
			map<char, int> que;
			que = pat;
			int c;
			cin>>c;

			for(auto const& pair:que)
			{
				que[pair.first] -= c;
			}

			int count = 0;
			for(auto const& pair:que)
			{
				if(pair.second>0)
					count += pair.second;
			}
			cout<<count<<endl;
		}
	}
	return 0;
}