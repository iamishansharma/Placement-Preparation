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
#define mod 1000000007

int rodCutting(vector<int> prices, int n)
{
    vector<int> dp(n + 1);

    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        dp[i] = INT_MIN;

        for (int j = 0; j < i; j++)
            dp[i] = max(dp[i], prices[j] + dp[i - j - 1]);
    }

    return dp[n];
}

void solve()
{
    // 1 2 3 4 5  6  7  8
    // 1 5 8 9 10 17 17 20

    int n = 0;
    cin >> n;

    vector<int> prices(n);

    for (int i = 0; i < n; i++)
        cin >> prices[i];

    cout << rodCutting(prices, n) << endl;
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