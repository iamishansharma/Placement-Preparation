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
	
	for(int i=0; i<n; i++)
	    cin>>v[i];
	
	int flag = 1;
	
    for(int i=0; i<n; i++)
    {
        if(i != 0)
        {
            if(!(v[i] > v[i-1]))
                flag = 0;
        }
        if(flag == 0)
            break;
    }
    
    cout<<flag<<endl;
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