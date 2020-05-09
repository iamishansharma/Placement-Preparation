#include <bits/stdc++.h>
using namespace std;

int main()
{
	int tc=0;
	string code;
	string ab = "abcdefghijklmnopqrstuvwxyz";
	cin>>tc>>code;

	map<char,char> m;

	m.clear();

	for(int i=0; i<code.length(); i++)
	{
		m[ab[i]] = code[i];
		m[ab[i]-32] = code[i]-32;
	}
	
	while(tc--)
	{
		string s;
		cin>>s;

		for(int i=0; i<s.length(); i++)
		{
			if(s[i] == '_')
			{
				cout<<" ";
			}
			else if((s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122))
			{
				cout<<m[s[i]];
			}
			else
			{
				cout<<s[i];
			}
		}
		cout<<endl;
	}
	return 0;
}