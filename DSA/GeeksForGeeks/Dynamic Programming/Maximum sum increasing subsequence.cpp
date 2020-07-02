#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

void solve()
{
	int n=0;
	cin>>n;
	
	vector<int> num(n);
	
	for(int i=0; i<n; i++)
	    cin>>num[i];
	    
    vector<int> sum(n, INT_MIN);
    
    // do here
    
    int ans = INT_MIN;
    
    for(int i=0; i<n; i++)
        ans = max(sum[i], ans);
        
    cout<<ans<<endl;
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