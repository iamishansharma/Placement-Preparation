#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

vector<int> ans;

void addEdge(vector<int> adj[], int u, int v) 
{ 
	adj[u].push_back(v); 
	adj[v].push_back(u); 
}

void printPath(vector<int> stack) 
{ 
	int i;

	for(i = 0; i < (int)stack.size() - 1; i++) 
		ans.push_back(stack[i]);

	ans.push_back(stack[i]);
} 

void DFS(vector<int> v[], bool vis[], int x, int y, vector<int> stack) 
{ 
	stack.push_back(x); 

	if(x == y) 
	{ 
		printPath(stack); 
		return; 
	} 

	vis[x] = true; 

	int flag = 0; 

	if(!v[x].empty()) 
	{ 
		for(int j = 0; j < v[x].size(); j++) 
		{ 
			if(vis[v[x][j]] == false) 
			{ 
				DFS(v, vis, v[x][j], y, stack); 
				flag = 1; 
			} 
		} 
	} 
	if(flag == 0) 
	{ 
		stack.pop_back(); 
	} 
} 

void DFSCall(int x, int y, vector<int> v[], int n, vector<int> stack) 
{ 
	bool vis[n + 1]; 
	memset(vis, false, sizeof(vis));
	DFS(v, vis, x, y, stack); 
}

void solve()
{
	ll n=0,q=0;
	cin>>n>>q;

	vector<int> v(n);
	
	for(int i=0; i<v.size(); i++)
		cin>>v[i];
	
	vector<int> adj[n];
	vector<int> stack;

	for(int i=0; i<n-1; i++)
	{
		ll u;
		ll v;

		cin>>u>>v;

		addEdge(adj, u-1, v-1); 
	}

	for(int i=0; i<q; i++)
	{
		ans.clear();

		ll a;
		ll b;

		cin>>a;
		cin>>b;

		a--;
		b--;

		DFSCall(a, b, adj, n, stack);

		vector<int> diff(ans.size());

		for(int i=0; i<ans.size(); i++)
		{
			diff[i] = v[ans[i]];
		}

		sort(diff.begin(), diff.end());

		int min = INT_MAX;

		for(int i=1; i<diff.size(); i++)
		{
			if(abs(diff[i] - diff[i-1]) < min)
				min = abs(diff[i] - diff[i-1]);
		}

		cout<<min<<endl;
	}
}

int main()
{
	fastIO;

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin); 
		freopen("output.txt", "w", stdout); 
	#endif
	
	int tc=0;
	cin>>tc;
	while(tc--)
	{
		solve();
	}
	return 0;
}