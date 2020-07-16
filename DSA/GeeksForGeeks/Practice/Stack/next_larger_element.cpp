#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
using namespace std;

void solve()
{
	ll n=0;
	cin>>n;
	
	vector<ll> arr(n);
	
	for(int i=0; i<n; i++)
	    cin>>arr[i];
	    
    stack<ll> s;
	    
    s.push(arr[n-1]);
    
    vector<ll> x(n);
    
    for(int i=n-1; i>=0; i--)
    {
        while(!s.empty() && arr[i] >= s.top())
            s.pop();
            
        x[i] = s.empty() ? -1 : s.top();
        s.push(arr[i]);
    }
    
    for(int i=0;i<n;i++)
        cout<<x[i]<<" ";
    cout<<endl;
}

int main()
{
	fastIO;

	/*#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif*/
	
	int tc=0;
	cin>>tc;
	while(tc--)
	{
		solve();
	}
	return 0;
}