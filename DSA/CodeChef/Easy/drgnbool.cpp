#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;

void solve()
{
	int n,m;
	cin>>n>>m;
	int a[n][2],b[m][2];

	for(int i=0;i<n;i++)
		for(int j=0;j<2;j++)
			cin>>a[i][j];

	for(int i=0;i<m;i++)
		for(int j=0;j<2;j++)
			cin>>b[i][j];

	int s=0;

	for(;;)
	{
		int c=0,k,l=0,p=0;

		for(int i=0;i<n;i++)
		{
			if(a[i][1]!=0)
			{
				k=a[i][1];
				p++;
				break;
			}
		}

		if(p==0)
		break;
		for(int i=0;i<n;i++)
		{
			if(a[i][1]==k)
			{
				c+=a[i][0];
				a[i][1]=0;
			}
		}
		for(int i=0;i<m;i++)
		{
			if(b[i][1]==k)
			{
				l+=b[i][0];
				b[i][1]=0;
			}
		}
		if(c<l)
		s+=(l-c);
	}
	cout<<s<<"\n";
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