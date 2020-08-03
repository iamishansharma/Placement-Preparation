#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

vector<int> StockSpan(vector<int> arr, int n)
{
    vector<int> span(n);
    stack<int> s;
    
    for(int i=0; i<n; i++)
    {
        while(!s.empty() && arr[s.top()] <= arr[i])
            s.pop();
        
        span[i] = s.empty() ? (i+1) : (i - s.top()); 
        
        s.push(i);
    }
    
    return span;
}

void solve()
{
	int n=0; 
	cin>>n;
	
	vector<int> arr(n);
	
	for(int i=0; i<n; i++)
	    cin>>arr[i];
	
	vector<int> ans = StockSpan(arr, n);
	
	for(int i=0; i<n; i++)
	    cout<<ans[i]<<" ";
	cout<<endl;
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