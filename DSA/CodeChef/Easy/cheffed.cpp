#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long int ll;
using namespace std;

ll sum(int x)
{
	ll a=0;
    while(x!=0)
    {
        a+=x%10;
        x/=10;
    }
    return a;
}

void solve()
{
	ll n=0;
	cin>>n;
    ll ans=0;
    for(ll i=n; i >= max((ll)0, n-90); i--)
    {
        if(i + sum(i) + sum(sum(i))== n)
            ans++;
    }
    cout<<ans<<endl;
}

int main()
{
	fastIO;

	/*#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif*/
	
	solve();
	return 0;
}