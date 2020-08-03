#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

bool cmp(pair<int,int> a, pair<int, int> b)
{
    return a.second < b.second;
}

void solve()
{
    int n=0;
    cin>>n;
    
    vector<int> st(n);
    vector<int> end(n);
    
    for(int i=0; i<n; i++)
        cin>>st[i];
    
    for(int i=0; i<n; i++)
        cin>>end[i];
        
    vector<pair<int,int>> act(n);
    
    for(int i=0; i<n; i++)
        act[i] = make_pair(st[i], end[i]);
    
    sort(act.begin(), act.end(), cmp);
    
    int count = 1;
    
    int active = act[0].second;
    
    for(int i=1; i<n; i++)
    {
        if(active <= act[i].first)
        {
            count++;
            active = act[i].second;
        }
    }
    
    cout<<count<<endl;
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