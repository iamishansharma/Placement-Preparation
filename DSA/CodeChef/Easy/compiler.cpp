#include <bits/stdc++.h>
using namespace std;

void solve()
{
	string s;
	cin>>s;

	int max = 0;
	int temp = 0;

	for(int i = 0; i<s.length(); i++)
	{
		if(s[i] == '<')
			temp++;
		else
			temp--;

		if(temp < 0)
			break;
		else if(temp == 0)
			max = i+1;
	}

	cout<<max<<endl;
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