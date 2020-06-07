#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

bool prearray(vector<int> pre, int n)
{
	stack<int> s; 
  
	int root = INT_MIN; 
  
	for (int i=0; i<n; i++) 
	{
		if(pre[i] < root) 
			return false; 
  
		while (!s.empty() && s.top()<pre[i]) 
		{ 
			root = s.top(); 
			s.pop(); 
		} 

		s.push(pre[i]); 
	} 
	return true; 
}

void solve()
{
	int n=0;
	cin>>n;
	
	vector<int> pre(n);
	
	for(int i=0; i<pre.size(); i++)
		cin>>pre[i];
	
	cout<<prearray(pre,n)<<endl;
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