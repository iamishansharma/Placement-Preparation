#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
typedef long long int ll;
using namespace std;

void solve()
{
	string s;
	cin >> s;
	cout << s;
	reverse(s.begin(), s.end());
	cout << s << endl;
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