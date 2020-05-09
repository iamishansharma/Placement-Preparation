#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;

void solve()
{
	long long int n;
	cin>>n;
	long long int id,sum,sum1=0,sum2=0,root;
	while(n--)
	{ 
		
		cin>>id>>sum;
		sum1 += + id;
		sum2 += sum;
	}
	cout<<sum1-sum2<<"\n";
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