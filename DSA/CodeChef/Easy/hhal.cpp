#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long int ll;
using namespace std;

void solve()
{
	string s;
	cin>>s;

	if(s.length()%2 == 0)
	{
		int ispal = 0;

		for(int i=0; i<s.length()/2; i++)
		{
			if(s[i] != s[s.length()-1-i])
				ispal = 1;
		}

		if(ispal)
			cout<<"2"<<endl;
		else
			cout<<"1"<<endl;
	}
	else
	{
		int ispal = 0;

		for(int i=0; i<=s.length()/2; i++)
		{
			if(s[i] != s[s.length()-1-i])
				ispal = 1;
		}

		if(ispal)
			cout<<"2"<<endl;
		else
			cout<<"1"<<endl;
	}
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