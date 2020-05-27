#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

void solve()
{
	ll n,k; 
	cin>>n>>k; 
	
	ll a[n],c=-1;
	
    for(int i=0;i<n;i++) 
        cin>>a[i];
        
    for(int i=0;i<n;i++) 
    {
        if(a[i]==k) 
        {
            c=i+1; 
            break;
        }
    }
    cout<<c<<endl;
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