#include <bits/stdc++.h>
using namespace std;
#define fastIO             ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)        {    cerr << #x << " = " << x <<endl;    }
#define ll                 long long int

void solve()
{
    ll n=0;
    cin>>n;

    vector<int> a(n);
    
    for(int i=0; i<a.size(); i++)
        cin>>a[i];

    vector<int> b(n);
    
    for(int i=0; i<b.size(); i++)
        cin>>b[i];
    
    ll posa = 0;
    ll posb = 0;

    ll ans = 0;

    for(int i=0; i<n; i++)
    {
        //cout<<posa<<" "<<posb<<endl;
        if(posa == posb)
        {
            if(a[i] == b[i])
                ans += a[i];
        }
        posa += a[i];
        posb += b[i];
    }

    cout<<ans<<endl;
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