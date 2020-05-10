#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long int ll;
using namespace std;

void solve()
{
	ll n,i;
    cin>>n;

    if(n==1)
    	cout<<"1";
    
    else if(n%2==0)
    {
        for(i=n/2;i<=n+n/2-1;i++)
        	cout<<i<<" ";
    }
    else if(n%2!=0)
    {
        for(i=(n-1)/2;i<=n+(n-1)/2-1;i++)
        	cout<<i<<" ";
    }

    cout<<endl;
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