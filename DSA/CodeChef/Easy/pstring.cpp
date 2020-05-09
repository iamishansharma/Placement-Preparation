#include <bits/stdc++.h>
using namespace std;

void solve()
{
	string s;
	int sum=0;

	cin>>s;

	for(int i=0; i<s.length(); i++)
	{
		if(s[i]<=57 && s[i]>=48)
			sum += (s[i]-48);
	}
	cout<<sum<<endl;
}

int main()
{
	int tc=0;
	cin>>tc;
	while(tc--)
	{
		solve();
	}
	return 0;
}