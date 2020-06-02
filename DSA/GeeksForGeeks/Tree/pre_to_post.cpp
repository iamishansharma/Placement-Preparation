#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

void findPostOrderUtil(int pre[], int n, int minval, int maxval, int& preIndex) 
{ 
    if (preIndex == n) 
        return; 
        
    if (pre[preIndex] < minval || pre[preIndex] > maxval) 
        return;
        
    int val = pre[preIndex]; 
    preIndex++;
    
    findPostOrderUtil(pre, n, minval, val, preIndex); 
    findPostOrderUtil(pre, n, val, maxval, preIndex); 
  
    cout << val << " "; 
}

void solve()
{
	int n=0;
	cin>>n;
	
	int pre[n];
	
	for(int i=0; i<n; i++)
        cin>>pre[i];
        
    int preIndex = 0;
    findPostOrderUtil(pre, n, INT_MIN, INT_MAX, preIndex);
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