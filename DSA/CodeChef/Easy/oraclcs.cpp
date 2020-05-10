#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;

void solve()
{
	int n=0;
	cin>>n; 
	int m = INT_MAX;
	for(int i=0; i<n; i++)
	{
		string s;
		cin>>s;
		int k = s.size();
		int a = count(s.begin(), s.end(), 'a');
		m = min(m, min(a, k-a));
	}
	cout << m << endl;
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