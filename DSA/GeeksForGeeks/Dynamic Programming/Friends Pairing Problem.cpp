#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

void solve()
{
	long long n;
    cin>>n;
    
    long long mat[n+1];
    
    mat[1] = 1;
    mat[2] = 2;
    
    for(long long i = 3; i <= n; i++)
        mat[i] = (mat[i-1] + ((i-1)*mat[i-2]))%1000000007;
        
    cout<<mat[n]<<endl;
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