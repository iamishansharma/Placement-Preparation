#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

void solve()
{
	int n = 0;
	cin>>n;
	
	vector<int> v(n);
	
	for(int i=0; i<n; i++)
	    cin>>v[i];
	    
	int k = 0;
	cin>>k;
	
	priority_queue<int> pq; // max_heap in STL
	
	for(int i=0; i<n; i++)
	    pq.push(v[i]);
	    
    int i = n-k;
    
    while(i--)
        pq.pop();
    
    cout<<pq.top()<<endl;
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