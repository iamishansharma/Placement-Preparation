#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n,a,b;
	cin>>n>>a>>b;

	unsigned int k1 = a;
	unsigned int c1 = 0; 
	while (k1) 
	{
		c1 += k1 & 1; 
		k1 >>= 1; 
	}
	a = c1;
	
	unsigned int k2 = b;
	unsigned int c2 = 0; 
	while (k2) 
	{
		c2 += k2 & 1; 
		k2 >>= 1; 
	}
	b = c2;

	int x = min(a,n-b) + min(b,n-a);

	int ans = 0;
	
	for(int i=0; i<x; i++)
	{
		ans += pow(2, n-1);
		n--;
	}
	cout << ans << "\n";
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