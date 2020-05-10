#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;

void solve()
{
	int n=0;
	cin>>n;

	set<int> s;

	for(int i=0; i<n; i++)
	{
		int temp = 0;
		cin>>temp;
		s.insert(temp);
	}

	cout<<s.size()<<endl;
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