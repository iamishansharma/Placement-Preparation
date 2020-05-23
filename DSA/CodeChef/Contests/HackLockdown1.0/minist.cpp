#include <bits/stdc++.h>
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int
using namespace std;

int N;

int tiv = 0; 

void minCashFlowRec(vector<int> amount) 
{
	int mxCredit = (max_element(amount.begin(),amount.end()) - amount.begin()); 
	int mxDebit = (min_element(amount.begin(),amount.end()) - amount.begin()); 
 
	if (amount[mxCredit] == 0 && amount[mxDebit] == 0) 
		return; 

	int minval = min(-amount[mxDebit], amount[mxCredit]); 
	amount[mxCredit] -= minval; 
	amount[mxDebit] += minval; 

	tiv += minval;
  
	minCashFlowRec(amount);
} 
  
void minCashFlow(vector<vector<int>> graph, vector<int> amount) 
{ 
	minCashFlowRec(amount);
	cout<<tiv<<endl;
}

void solve()
{
	int n=0;
	int m=0;
	cin>>n>>m;

	N = n;

	vector<vector<int>> graph(n, vector<int> (n));

	vector<int> amt(N);

	for(int i=0; i<m; i++)
	{
		int t1,t2,money;
		cin>>t1>>t2>>money;

		graph[t1-1][t2-1] += money;

		amt[t1-1] += money;
		amt[t2-1] -= money;
	}

	minCashFlow(graph,amt);
}

int main()
{
	fastIO;

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin); 
		freopen("output.txt", "w", stdout); 
	#endif
	
	solve();
	return 0;
}