#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long int ll;
using namespace std;

void solve()
{
	int  x = 0, y, n, sol = 0,energy = 0;
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> y;
        energy += x-y;
        if(energy < 0)
        {
            sol += -energy;
            energy = 0;
        }
        x = y;
    }
    cout<<sol<<"\n";
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