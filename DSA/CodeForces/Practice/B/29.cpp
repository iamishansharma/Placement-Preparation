#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
typedef long long int ll;
using namespace std;

void solve()
{
	int n=0;
	int k=0;

	cin>>n>>k;

	vector<int> v(n);
	
	for(int i=0; i<v.size(); i++)
		cin>>v[i];
	
	vector<int> sum(n);

	for(int i=0; i<k-1; i++)
		sum[i] = INT_MAX;

	for(int i=0; i<k; i++)
	{
		sum[k-1] += v[i];
	}

	for(int i=1; i<=n-k; i++)
	{
		sum[i+(k-1)] = sum[i+k-2] - v[i-1] + v[i+(k-1)];
	}

	cout<<min_element(sum.begin(),sum.end()) - sum.begin()-k+2<<endl;
}

int main()
{
	fastIO;

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin); 
		freopen("output.txt", "w", stdout); 
	#endif
	
	solve();
}