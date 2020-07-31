#include <bits/stdc++.h>
using namespace std;
#define fastIO          ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)        {   cerr << #x << " = " << x <<endl;    }
#define ll              long long int

void solve()
{
    ll n = 0;
    cin>>n;
    
    vector<ll> arr(n);
    
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    ll prefix = 0;
    unordered_map<ll,ll> mp;
    
    ll count = 0;
    
    for(int i=0; i<n; i++)
    {
        prefix += arr[i];
        
        if(prefix == 0)
            count++;
        
        if(mp[prefix] != 0)
            count += mp[prefix];
        
        mp[prefix]++;
    }
    
    cout<<count<<endl;
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