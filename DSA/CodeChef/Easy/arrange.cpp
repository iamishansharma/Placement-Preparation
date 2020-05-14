#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long int ll;
using namespace std;

int reverse(int n, int k)
{
	int sum = 0;
	for (int i = 0; i<k; i++)
	{
		sum<<=1;
		sum|=(n&1);
		n>>=1;
	}
	return sum;
}

void solve()
{
	int k=0;
	string a;
	cin>>k>>a;

	string b = a;

	for (int i = 0; i < (1 << k); i++)
		b[reverse(i, k)] = a[i];

	cout<<b<<endl;
}

int main()
{
	fastIO;

	/*#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif*/
	
	int tc=0;
	cin>>tc;
	while(tc--)
	{
		solve();
	}
	return 0;
}