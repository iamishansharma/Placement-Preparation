#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin >> n;
	char start='a';
	for(int i=0;i<n;i++)
	{
		cout << start;
		start++;
		if(start>'z') 
			start-=26;
	}
	cout << endl;
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