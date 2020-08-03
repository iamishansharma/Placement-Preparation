#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

vector<int> MaxSubArrayK(vector<int> arr, int n, int k)
{
    vector<int> ans;
    
    deque<int> dq(k);
    
    for(int i=0; i<k; i++)
    {
        while(!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back();
        
        dq.push_back(i);
    }
    
    for(int i=k; i<n; i++)
    {
        ans.push_back(arr[dq.front()]);
        
        while(!dq.empty() && dq.front() <= i - k)
            dq.pop_front();
            
        while(!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back();
        
        dq.push_back(i);
    }
    
    ans.push_back(arr[dq.front()]);
    
    return ans;
}

void solve()
{
	int n=0;
	cin>>n;
	
	int k=0;
	cin>>k;
	
	vector<int> arr(n);
	
	for(int i=0; i<n; i++)
	    cin>>arr[i];
	
	vector<int> v = MaxSubArrayK(arr, n, k);
	
	for(int i=0; i<v.size(); i++)
	    cout<<v[i]<<" ";
	
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