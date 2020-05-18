#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long int ll;
using namespace std;

void solve()
{
	int n;
	cin>>n;

	string s;
	cin>>s;

	int count = 0;

	for(int i=0; i<n-1; i++)
	{
		if(s[i] == s[i+1])
			count++;
	}

	cout<<count<<endl;
}

int main()
{
	fastIO;

	/*#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif*/
	
	solve();
}