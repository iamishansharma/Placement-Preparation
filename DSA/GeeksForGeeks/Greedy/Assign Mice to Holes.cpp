#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

void solve()
{
	int n;
    cin>>n;
    int mice[10001];
    int hole[10001];
    
    for(int i=0;i<n;i++)
        cin>>mice[i];
        
    sort(mice,mice+n);
    
    for(int i=0;i<n;i++)
        cin>>hole[i];
        
    sort(hole,hole+n);
    
    int m = INT_MIN;
    for(int i=0; i<n; i++)
    {
        if(abs(mice[i]-hole[i]) > m)
            m = abs(mice[i]-hole[i]);
    }
    cout<<m<<endl;
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