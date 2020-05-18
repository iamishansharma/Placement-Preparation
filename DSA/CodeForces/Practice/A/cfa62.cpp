#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long int ll;
using namespace std;

void solve()
{
	char d;
	cin>>d;

	string s;
	cin>>s;

	string r1 = "qwertyuiop";
	string r2 = "asdfghjkl;";
	string r3 = "zxcvbnm,./";

	if(d == 'R')
	{
		map<char,char> m;

		m.clear();

		for(int i=0; i<=r1.length()-2; i++)
			m[r1[i+1]] = r1[i];

		for(int i=0; i<=r2.length()-2; i++)
			m[r2[i+1]] = r2[i];

		for(int i=0; i<=r3.length()-2; i++)
			m[r3[i+1]] = r3[i];

		for(int i=0; i<s.length(); i++)
			cout<<m[s[i]];

		cout<<endl;
	}
	else
	{
		map<char,char> m;

		m.clear();

		for(int i=1; i<=r1.length()-1; i++)
			m[r1[i-1]] = r1[i];

		for(int i=1; i<=r2.length()-1; i++)
			m[r2[i-1]] = r2[i];

		for(int i=1; i<=r3.length()-1; i++)
			m[r3[i-1]] = r3[i];

		for(int i=0; i<s.length(); i++)
			cout<<m[s[i]];

		cout<<endl;
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