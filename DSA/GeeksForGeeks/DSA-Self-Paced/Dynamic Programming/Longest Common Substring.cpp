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
    int n, m;
    cin >> n >> m;

    string s1;
    string s2;

    cin >> s1 >> s2;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    int maxval = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = 0;

            maxval = max(maxval, dp[i][j]);
        }
    }

    // 	for(int i=0; i<=n; i++)
    // 	{
    // 	    for(int j=0; j<=m; j++)
    // 	    {
    // 	        cout<<dp[i][j]<<" ";
    // 	    }
    // 	    cout<<endl;
    // 	}

    cout << maxval << endl;
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