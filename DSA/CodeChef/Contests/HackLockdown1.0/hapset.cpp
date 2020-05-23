#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
typedef long long int ll;
#define mod 1000000007
using namespace std;

ll fact (ll n)
{ 
	if (n == 0) 
		return 1; 
	else
		return (n * fact(n-1) % mod); 
} 
  
ll findcombination(ll n,ll r)
{ 
	return(fact(n) / (fact(n - r) * fact(r))); 
} 
 
ll find(ll arr[], ll n, ll d, ll k) 
{ 
	sort(arr,arr+n); 

	ll ans = 0, end = n, co = 0, start = 0; 

	for (int i = 0; i < n; i++) 
	{ 
  
		ll val = arr[i] + d; 
		  
		start = i; 
		while (start < end - 1)
		{ 
			ll mid = (start + end) / 2; 
			if (arr[mid] > val) 
				end = mid; 
	  
			else
				start = mid + 1; 
		} 
	  
		if (start != n and arr[start]  
						   <= val) 
				start += 1; 
	  
		ll c = start-i; 

		if (c >= k)
		{ 
			co += (findcombination(c - 1, k - 1));
		} 
	} 
	return co; 
}

void solve()
{
	ll n,k,d;

	cin>>n>>k>>d;

	ll arr[n];

	for(int i=0; i<n; i++)
		cin>>arr[i];

	cout << find(arr, n,d,k);
}

int main()
{
	fastIO;

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin); 
		freopen("output.txt", "w", stdout); 
	#endif
	
	solve();
}