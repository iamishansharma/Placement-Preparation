#include <bits/stdc++.h>
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define elif else if
#define pii pair<ll int,ll int>
#define mp make_pair
#define pb push_back
using namespace std;

vector<int>v;
int mv,n;

vector<vector<int> > mul(vector<vector<int> > a,vector<vector<int> > b)
{
 	int i,j,k,r=a[0].size(),c=a.size();
 	vector< vector<int> > ans(r);
 	for(i=0;i<r;i++)
	{
		ans[i].resize(c,0);
		for(j=0;j<c;j++)
		{
			for(k=0;k<r;k++)
				ans[i][j]+= a[i][k]*b[k][j];
		}
	}
 	return ans;
}
 
vector<vector< int > > mat_pow(vector<vector< int > > mat,int n)
{
	if(n==1)
	  return mat;

	vector<vector<int>> ans = mat_pow(mat,n/2);

	ans=mul(ans,ans);

	if(n%2)
	  ans=mul(mat,ans);
	
	return ans;
}

int foo()
{
	int i,j;

	vector<vector<int>> mat(n);

	for(i=0;i<n;i++)
	{
		mat[i].resize(n,0);

		int fac = 2;

		if(v[i] % fac==0)
		{
			if(i+fac<n)
				mat[i][i+fac]=1;
			if(i-fac>=0)
				mat[i][i-fac]=1;
			while(v[i]%fac==0)
				v[i]/=fac;
		}
		for(fac=3; fac*fac <=v[i]; fac += 2)
		{
			if(v[i]%fac==0)
			{
				if(i+fac<n)
					mat[i][i+fac]=1;
				if(i-fac>=0)
					mat[i][i-fac]=1;
				while(v[i]%fac==0)
					v[i]/=fac;
			}
		}
		if(v[i] > 1)
		{
			fac=v[i];
			if(i+fac<n)
				mat[i][i+fac]=1;
			if(i-fac>=0)
				mat[i][i-fac]=1;
		}
	}
	mat = mat_pow(mat,mv);

	return mat[0][n-1];
}

void solve()
{
	int i,j,m;
	cin>>n;

	assert(n>=2 && n<=40);

	v.clear();
	v.resize(n);
	rep(i,n)
	{
		cin>>v[i];
		assert(v[i]>=1 && v[i]<=1000000);
	}

	cin>>mv;
	assert( mv>=1 && mv<=1000000);

	if(foo())
		cout<<"YES\n";
	else
		cout<<"NO\n";
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