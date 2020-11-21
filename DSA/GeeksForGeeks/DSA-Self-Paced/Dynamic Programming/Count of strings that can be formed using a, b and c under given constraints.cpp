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

int Memo(vector<vector<vector<int>>> &dp, int n, int b, int c)
{
    if (b < 0 || c < 0 || n < 0)
        return 0;

    if (n == 0)
        return 1;

    if (dp[n][b][c] != -1)
        return dp[n][b][c];

    dp[n][b][c] = Memo(dp, n - 1, b, c) + Memo(dp, n - 1, b - 1, c) + Memo(dp, n - 1, b, c - 1);

    return dp[n][b][c];
}

void solve()
{
    int n = 0;
    cin >> n;

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));

    cout << Memo(dp, n, 1, 2) << endl;
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