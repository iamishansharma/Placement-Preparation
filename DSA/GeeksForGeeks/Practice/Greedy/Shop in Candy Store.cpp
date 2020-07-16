#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

bool comp(int a, int b)
{
    return a > b;
}

int util(deque<int> dq, int k)
{
    int sum = 0;
    
    while(!dq.empty())
    {
        sum += dq.front();
        int dqsize = dq.size()-1;
        int minval = min(dqsize, k);
        
        while(minval--)
            dq.pop_back();
            
        dq.pop_front();
    }
    
    return sum;
}

void solve()
{
	int n=0;
	cin>>n;
	
	int k=0;
	cin>>k;
	
	vector<int> candy(n);
	
	for(int i=0; i<n; i++)
	    cin>>candy[i];
	
	sort(candy.begin(), candy.end());    
	
	deque<int> dq1;
	
	for(auto i: candy)
	    dq1.push_back(i);
	
	int minval = util(dq1, k);
	
	sort(candy.begin(), candy.end(), comp);    
	
	deque<int> dq2;
	
	for(auto i: candy)
	    dq2.push_back(i);
	
	int maxval = util(dq2, k);
	
	cout<<minval<<" "<<maxval<<endl;
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