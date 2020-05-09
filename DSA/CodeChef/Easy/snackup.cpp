#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;

void solve()
{
	int n=0,p=0,t=0;
	cin>>n;
	vector<int> v(n);

	for(int i=0;i<n;i++)
		v[i]=i+1;

	cout<<n<<"\n";

	for(int i=0;i<n;i++)
	{
		cout<<n<<"\n";
		t=i;
		for(int j=1;j<=n;j++)
		{
		    cout<<j<<" ";
			for(int p=0;p<2;p++)
			    cout<<v[(t+p)%n]<<" ";
			cout<<"\n";
			t++;
		}
	}
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