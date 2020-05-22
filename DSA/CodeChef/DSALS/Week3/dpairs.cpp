#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;

void solve()
{
	long long int n,m,k,i;
	cin>>n>>m;
	vector<pair <long long int,long int> > a,b;

	for(i=0;i<n;i++)
	{
		cin>>k;
		a.push_back(make_pair(k,i));
	}
	
	for(i=0;i<m;i++)
	{
		cin>>k;
		b.push_back(make_pair(k,i));
		
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	if(n>m)
	{
		for(i=0;i<m;i++)
			cout<<a[i].second<<" "<<b[i].second<<endl;
		for(i=0;i<m;i++)
			cout<<a[i+1].second<<" "<<b[i].second<<endl;
		for(i=m+1;i<n;i++)
			cout<<a[i].second<<" "<<b[m-1].second<<endl;
	}
	else if(n==m)
	{   
		for(i=0;i<n;i++)
			cout<<a[i].second<<" "<<b[i].second<<endl;
		for(i=0;i<n-1;i++)
			cout<<a[i].second<<" "<<b[i+1].second<<endl;	
	}
	else
	{
		for(i=0;i<n;i++)
			cout<<a[i].second<<" "<<b[i].second<<endl;
		for(i=0;i<n;i++)
			cout<<a[i].second<<" "<<b[i+1].second<<endl;
		for(i=n+1;i<m;i++)
			cout<<a[n-1].second<<" "<<b[i].second<<endl;
	}
}

int main()
{
	fastIO;
	solve();
	return 0;
}