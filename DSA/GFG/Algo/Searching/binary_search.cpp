#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

int binary_search()
{
    ll n,k; 
	cin>>n>>k; 
	
	ll a[n];
	
    for(int i=0;i<n;i++) 
        cin>>a[i];
        
    int flag = 0;
    
    ll low = 0;
    ll high = n-1;
    ll mid = 0;
    
    while(low <= high)
    {
        mid = low + (high-low)/2;
        
        if(a[mid] == k)
        {
            return 1;
        }
        
        if(k < a[mid])
            high = mid-1;
        else if(k > a[mid])
            low = mid+1;
    }
    return -1;
}

void solve()
{
	cout<<binary_search()<<endl;
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