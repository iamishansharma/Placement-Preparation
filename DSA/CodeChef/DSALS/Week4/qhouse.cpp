#include <bits/stdc++.h>
//#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int
using namespace std;

void solve()
{
	int lo = 0, hi = 1000, side, height;
	while(lo <= hi)
	{
		int mid = lo + (hi-lo)/2;
		printf("? %d 0\n",mid);
		fflush(stdout);
		string s;
		cin>>s;

		if(s=="YES")
			lo=mid+1;
		else
			hi=mid-1;
	}
	side = 2*(lo-1);

	lo=0;
	hi=1000;

	while(lo<=hi)
	{
		int mid=lo+(hi-lo)/2;
		printf("? %d %d\n",mid,side);
		fflush(stdout);
		string s;
		cin>>s;
		if(s=="YES")
			lo=mid+1;
		else
			hi=mid-1;
	}

	int base = (lo-1)*2;

	lo=0;
	hi=1000;

	while(lo<=hi)
	{
		int mid=lo+(hi-lo)/2;
		printf("? 0 %d\n",mid);
		fflush(stdout);
		string s;
		cin>>s;
		if(s=="YES")
			lo=mid+1;
		else
			hi=mid-1;
	}

	height = lo-1;
	height -= side;

	int answer = side*side + (base*height)/2;
	printf("! %d\n",answer);
	fflush(stdout);
}

int main()
{
	/*#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin); 
		freopen("output.txt", "w", stdout); 
	#endif*/
	
	solve();
	return 0;
}