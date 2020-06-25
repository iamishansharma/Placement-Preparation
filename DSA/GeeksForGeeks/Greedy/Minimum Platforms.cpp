#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

void solve()
{
	int n;
    cin>>n;
    
    vector<pair<int,char>> arr;
    
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        
        arr.push_back({x,'a'});
    }
    
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        
        arr.push_back({x,'d'});
    }
    
    sort(arr.begin(), arr.end());

    int final[arr.size()];
    final[0] = 1;
    
    for(int i=1; i<arr.size(); i++)
    {
        if(arr[i].second == 'a') 
            final[i] = final[i-1] + 1;
        else 
            final[i] = final[i-1] - 1;
    }
    
   cout << *max_element(final, final + arr.size()) << endl;
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