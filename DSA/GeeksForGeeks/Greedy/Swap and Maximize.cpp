#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

void solve()
{
	int n,i;
    cin>>n;
    
    int a[n];
    
    for(i=0; i<n; i++)
        cin>>a[i];
        
    sort(a,a+n);
    
    int l=0, r=n-1, k=0;
    long int sum=0;
    
    while(l<r) 
    {
        sum += (abs(a[l]-a[r]));
        
        if(k%2 == 0) 
        {
            l++;
            k = 1;
        }
        else 
        {
            r--;
            k=0;
        }
    }
    cout << sum + (abs(a[0]-a[r])) << endl;
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