#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

bool comp(pair<int,int> a, pair<int,int> b)
{
    return a.first < b.first;
}

vector<pair<int,int>> MergeIntervals(vector<pair<int,int>> intervals)
{
    int n = intervals.size();
    
    if(n == 1)
        return intervals;
        
    sort(intervals.begin(), intervals.end(), comp);
    
    /*for(int i=0; i<intervals.size(); i++)
	    cout<<intervals[i].first<<" "<<intervals[i].second<<" ";*/
	    
	//cout<<endl;
	
	int start = intervals[0].first;
	int end = intervals[0].second;
	
	vector<pair<int,int>> ans;
	
	for(int i=1; i<n; i++)
	{
	    if(intervals[i].first <= end)
	        end = max(end, intervals[i].second);
	    else
	    {
	        ans.push_back({start,end});
	        
	        start = intervals[i].first;
	        end = intervals[i].second;
	    }
	}
	ans.push_back({start,end});
	
	return ans;
}

void solve()
{
	int n = 0;
	cin>>n;
	
	vector<pair<int,int>> intervals(n);
	
	for(int i=0; i<n; i++)
	{
	    int temp1, temp2;
	    cin>>temp1;
	    cin>>temp2;
	    
	    intervals[i] = {temp1,temp2};
	}
	
	vector<pair<int,int>> ans = MergeIntervals(intervals);
	
	for(int i=0; i<ans.size(); i++)
	    cout<<ans[i].first<<" "<<ans[i].second<<" ";
	    
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