#include <bits/stdc++.h>
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int
using namespace std;

int foo(int a[],int k1,int n)
{
	int ans=0,i,j,k,g;

	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			g=INT_MAX;

			for(k=i; k<=j; k++)
			{
				g=min(g,a[k]);
			}

			if(g==k1)
				ans++;
		}
	}
	return ans;

}

void solve()
{
	int n,i,q,k;
	cin>>n;

	int a[n];

	for(i=0;i<n;i++)
		cin>>a[i];

	cin>>q;

	while(q--)
	{
		cin>>k;
		cout<<foo(a,k,n)<<endl;
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
	return 0;
}