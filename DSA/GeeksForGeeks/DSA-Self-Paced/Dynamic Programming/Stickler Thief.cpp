#include <bits/stdc++.h>
using namespace std;
#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define debug(x)                          \
    {                                     \
        cerr << #x << " = " << x << endl; \
    }
#define ll long long int

int SticklerThief(int n, vector<int> &houses)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return houses[0];
    else if (n == 2)
        return max(houses[0], houses[1]);
    else
    {
        vector<int> dp(n, 0);

        dp[0] = houses[0];
        dp[1] = max(dp[0], houses[1]);

        for (int i = 2; i < n; i++)
            dp[i] = max(houses[i] + dp[i - 2], dp[i - 1]);

        // 	for(int i=0; i<n; i++)
        // 	    cout<<dp[i]<<" ";
        // 	cout<<endl;

        return dp[n - 1];
    }
}

void solve()
{
    int n = 0;
    cin >> n;

    vector<int> houses(n);

    for (int i = 0; i < n; i++)
        cin >> houses[i];

    cout << SticklerThief(n, houses) << endl;
}

int main()
{
    fastIO;

    int tc = 0;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}