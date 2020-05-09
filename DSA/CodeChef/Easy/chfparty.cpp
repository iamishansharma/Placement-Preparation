#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> friends(n);

	for(int i=0; i<n; i++)
	{
		cin>>friends[i];
	}

	sort(friends.begin(),friends.end());

	int count = 0;

	if(friends[0] != 0)
	{
		cout<<count<<endl;
		return;
	}
	else
	{
		for(int i=0; i<n; i++)
		{
			if(friends[i] <= count)
			{
				count++;
			}
			else
			{
				break;
			}
		}
		cout<<count<<endl;
		return;
	}
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