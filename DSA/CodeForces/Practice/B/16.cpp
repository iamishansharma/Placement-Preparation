#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long int ll;
using namespace std;

void solve()
{
	int n=0;
	cin>>n;

	string s;
	cin>>s;

	string ans = s;

	if(n % 2 == 0)
	{

	}
	else
	{
		int mid = n/2+1;

		ans[mid] = s[0];

		int it = 1;

		for(int i=1; i <= n/2; i++)
		{
			ans[mid-i] = s[it++];
			ans[mid+i] = s[it++];
		}

		cout<<ans<<endl;
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