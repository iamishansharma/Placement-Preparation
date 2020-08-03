#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int
#define MOD 1000000007

void solve()
{
	int n=0;
	cin>>n;
	
	int r=0;
	cin>>r;
	
	vector<int> C(r+1, 0);
	
	C[0] = 1;
	
	for (int i = 1; i <= n; i++) 
    {
        for (int j = min(i, r); j > 0; j--) 
            C[j] = (C[j] + C[j-1]) % MOD; 
    }
    
    cout<<C[r]<<endl;
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