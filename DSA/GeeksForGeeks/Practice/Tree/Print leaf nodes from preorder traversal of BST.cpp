#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

void printleaf(vector<int> arr, int l, int h)
{
    if(l > h)
        return;
        
    if(l == h)
        cout<<arr[l]<<" ";
        
    int i;
    
    for(i = l+1; i<=h; i++)
        if(arr[i] > arr[l])
            break;
            
    printleaf(arr,l+1,i-1);
    printleaf(arr,i,h);
}

void solve()
{
	int n=0;
	cin>>n;
	
	vector<int> v(n);
	
	for(int i=0; i<n; i++)
	    cin>>v[i];
	
	printleaf(v, 0, n-1);
	
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