#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

bool isPrime(ll n) 
{ 
    // Corner cases 
    if (n <= 1)  
    	return false; 
    if (n <= 3)  
    	return true; 

    if (n%2 == 0 || n%3 == 0) return false; 
  
    for (ll i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
  
    return true; 
}

void solve()
{
	ll n=0;
	ll k=0;

	cin>>n>>k;

	if(k >= n)
		cout<<"1"<<endl;
	else
	{
		if(isPrime(n))
			cout<<n<<endl;
		else
		{
			if(k == 1)
				cout<<n<<endl;
			else
			{
				/*for(ll i=k; i>=2; i--)
				{
					if(n % i == 0)
					{
						cout<<n/i<<endl;
						break;
					}
				}TLE*/

				
			}
		}
	}
}

int main()
{
	fastIO;

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin); 
		freopen("output.txt", "w", stdout); 
	#endif
	
	int tc=0;
	cin>>tc;
	while(tc--)
	{
		solve();
	}
	return 0;
}