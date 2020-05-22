#include <bits/stdc++.h>
using namespace std;
const int mod=1e9 + 7;
#define int long long
const int inf=1e18;
const int N=1e6 + 100;
#define pii pair<int, int>
#define f first
#define s second 
#define mp make_pair
#define FOR(i, n) for(int i=1;i<=n;i++)
#define TRACE(x) cerr << #x << " = " << x << endl
int n, m, arr[N];
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	assert(n<=1e6);
	assert(m<=2e5);
	arr[0]=inf;
	set<int> start;
	for(int i=1;i<=n;i++) 
	{
		cin>>arr[i];
		assert(arr[i]<=1e6);
		if(arr[i]%arr[i-1]!=0) 
			start.insert(i);
	}
	arr[n+1]=mod;
	while(m--)
	{
		int t;
		cin>>t;
		assert(t==1||t==2);
		if(t==1)
		{
			int ind, val;
			cin>>ind>>val;
			assert(ind<=n);
			assert(val<=1e6);
			arr[ind]=val;

			if(arr[ind]%arr[ind-1]!=0) 
				start.insert(ind);
			else 
				start.erase(ind);
			if(arr[ind+1]%arr[ind]!=0) 
				start.insert(ind+1);
			else 
				start.erase(ind+1);
		}
		else
		{
			int ind;cin>>ind;
			set<int>::iterator it=start.upper_bound(ind);
			it--;
			cout<<(*it)<<endl;
		}
	}
}