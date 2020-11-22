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

int MaxTipCal(int n, int x, int y, vector<int> &rahul, vector<int> &ankit, vector<vector<int>> &dp)
{
    if (n < 0)
        return 0;

    if (dp[x][y] != -1)
        return dp[x][y];

    if (x > 0 && y > 0)
        return dp[x][y] = max(MaxTipCal(n - 1, x - 1, y, rahul, ankit, dp) + rahul[n], MaxTipCal(n - 1, x, y - 1, rahul, ankit, dp) + ankit[n]);
    else if (x > 0)
        return dp[x][y] = rahul[n] + MaxTipCal(n - 1, x - 1, y, rahul, ankit, dp);
    else if (y > 0)
        return dp[x][y] = ankit[n] + MaxTipCal(n - 1, x, y - 1, rahul, ankit, dp);
}

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> rahul(n);
    vector<int> ankit(n);

    for (int i = 0; i < n; i++)
        cin >> rahul[i];

    for (int i = 0; i < n; i++)
        cin >> ankit[i];

    vector<vector<int>> dp(x + 1, vector<int>(y + 1, -1));

    cout << MaxTipCal(n - 1, x, y, rahul, ankit, dp) << endl;
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