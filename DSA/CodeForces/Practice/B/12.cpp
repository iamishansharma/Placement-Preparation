#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long int ll;
using namespace std;

void solve()
{
	string s;
	cin>>s;

	int ans = 0;
    while(s.size() != 1)
    {
        int n = 0;

        for(int i=0; i<s.length(); ++i) 
        	n += s[i]-'0';

        s = to_string(n);

        ans++; 
    } 
    cout << ans << endl;
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