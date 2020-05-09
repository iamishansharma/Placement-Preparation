#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int l=0,r=0;
	cin>>l>>r;

	int count = 0;

	for(int i=l; i<=r; i++)
	{
		int first = i%10;

		if(first == 2 || first == 3 || first == 9)
			count++;
	}

	cout<<count<<endl;
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