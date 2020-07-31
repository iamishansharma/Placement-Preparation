#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

ll LongestSubArraySumK(vector<ll> arr, int n, int k)
{
    unordered_map<ll, ll> um; 
    ll sum = 0, maxLen = 0; 
    
    for (int i = 0; i < n; i++) 
    { 
        sum += arr[i]; 

        if(sum == k) 
            maxLen = i + 1; 

        if(um.find(sum) == um.end()) 
            um[sum] = i; 

        if(um.find(sum - k) != um.end())
            maxLen = max(maxLen, i - um[sum-k]);
    } 

    return maxLen; 
}

void solve()
{
	ll n=0;
	cin>>n;
	
	ll k=0;
	cin>>k;
	
	vector<ll> arr(n);
	
	for(int i=0; i<n; i++)
	    cin>>arr[i];
	
	cout<<LongestSubArraySumK(arr, n, k)<<endl;
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