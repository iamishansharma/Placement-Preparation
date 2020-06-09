#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

void solve()
{
    int n=0;
    cin>>n;

    vector<int> v(n);
    
    for(int i=0; i<v.size(); i++)
    	cin>>v[i];
    
    int min = INT_MAX;

    for(auto i:v)
    	if(i < min)
    		min = i;

    cout<<min<<endl;
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