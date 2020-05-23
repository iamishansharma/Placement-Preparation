#include <bits/stdc++.h>
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int
using namespace std;

void gZ(string str, ll n, ll Z[]) 
{ 
	ll L, R, k;

	L = R = 0; 

	for (int i = 1; i < n; ++i) 
	{ 
		if (i > R) 
		{ 
			L = R = i;
			while (R < n && str[R - L] == str[R]) 
				R++; 
			Z[i] = R - L; 
			R--; 
		}
		else 
		{ 
			k = i - L;

			if (Z[k] < R - i + 1) 
				Z[i] = Z[k]; 

			else 
			{ 
				L = i; 
				while (R < n && str[R - L] == str[R]) 
					R++; 
				Z[i] = R - L; 
				R--; 
			} 
		} 
	} 
}

ll sS(string s, int n) 
{ 
	ll Z[n] = { 0 }; 

	gZ(s, n, Z); 

	ll total = n;

	for (int i = 1; i < n; i++) 
		total += Z[i]; 
  
	return total; 
}

void solve()
{
	string s;
	cin>>s;

	ll n = s.length();

	cout << sS(s, n) <<endl;;
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