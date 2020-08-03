#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			unsigned long int

void solve()
{
	int n=0;
	cin>>n;
	
	cpp_int cat[n+1]={0};
	
	cat[0] = 1;
	cat[1] = 1;
	
	for(int i=2; i<=n; i++)
	{
	    cat[i] = 0;
	    for(int j=0; j<i; j++)
	        cat[i] += cat[j] * cat[i-j-1];
	}
	    
    cout<<cat[n]<<endl;
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