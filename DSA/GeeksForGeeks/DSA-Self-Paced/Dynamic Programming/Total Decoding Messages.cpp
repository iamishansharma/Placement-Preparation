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

void solve()
{
    int n = 0;
    cin >> n;

    string s;
    cin >> s;

    vector<int> dp(n + 1, 0);

    dp[0] = 1;
    dp[1] = s[0] == '0' ? 0 : 1;

    for (int i = 2; i <= n; i++)
    {
        if (s[i - 1] >= '1')
            dp[i] += dp[i - 1];

        int double_digit = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');

        if (double_digit >= 10 && double_digit <= 26)
            dp[i] += dp[i - 2];
    }

    cout << dp[n] << endl;
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