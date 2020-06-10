#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cout << #x << " = " << x <<endl;	}
#define ll	 			long long int

bool comp(pair<int,int> a, pair<int, int> b)
{
    return (float) a.first/a.second > (float) b.first/b.second;
}

void solve()
{
	int n=0;
	cin>>n;
	
	int w=0;
	cin>>w;
	
	vector<pair<int,int>> items(n);
	
	for(int i=0; i<n; i++)
	{
	    int temp1, temp2;
	    cin>>temp1>>temp2;
	    
	    items[i] = {temp1,temp2};
	}
	
	sort(items.begin(), items.end(), comp);
	
	double total = 0;
	
	int i=0;
	
	while(w != 0 && i<n)
	{
	    if(items[i].second <= w)
	    {
	        total += items[i].first;
	        w -= items[i].second;
	        i++;
	    }
	    else
	    {
	        double part = (double) w / (double) items[i].second;
	        total += part*items[i].first;
	        w -= w;
	        i++;
	    }
	}
	
	cout<<fixed<<setprecision(2)<<total<<endl;
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