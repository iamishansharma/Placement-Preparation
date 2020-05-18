#include <bits/stdc++.h>
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int
using namespace std;

const ll N=2e6;
ll aol[N],ael[N],isl[N];

void solve()
{
	ll n;
	cin>>n;

	for(ll i=0;i<=n;i++)
	{
		isl[i]=-1;
		aol[i]=-1;
		ael[i]=-1;
	}

	ll ol=0,el=0,res=0,b=1;

	aol[1]=1;
	ael[1]=0;
	isl[1]=1;

	ol++;

	for(ll i=1;i<=n;i++)
	{
		ll ai;
		cin>>ai;

		if (ai==1 && b==1)
		{
			isl[2]=1;
			isl[1]=1;
			ael[2]=1;
			aol[2]=0;
			el=1;
			ol=1;
			res += max(el,ol);
			b=0;
			continue;
		}

		isl[i+1]=1;
		
		if (aol[ai])
		{
			aol[i+1]=0;
			ael[i+1]=1;
			if(isl[ai])
			{
				ol--;
				el++;
			}
			else
			{
				el++;
			}
		}
		else if (ael[ai])
		{
			ael[i+1]=0;
			aol[i+1]=1;
			if(isl[ai])
			{
				el--;
				ol++;
			}
			else
			{
				ol++;
			}
		}
		isl[ai]=0;
		res+=max(el,ol);
	}
	cout<<res<<endl;
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