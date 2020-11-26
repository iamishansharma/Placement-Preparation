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

void solve()
{
    float k; //k->water in litres
    cin >> k;
    int n, m;
    cin >> n >> m; //n->rows  m->cols
    float dp[n + 1][2 * n + 1];
    bool vis[n + 1][2 * n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < (2 * n + 1); j++)
        {
            dp[i][j] = 0;
            vis[i][j] = false;
        }
    }
    queue<pair<int, int>> q;
    dp[0][n] = k;
    q.push({0, n});
    vis[0][n] = true;
    while (!q.empty())
    {
        pair<int, int> temp = q.front();
        q.pop();
        int i = temp.first;
        int j = temp.second;
        if (i == n)
            break;
        float x = dp[i][j];
        if (float((x - 1.0) / 2.0) < 0)
        {
            dp[i + 1][j - 1] += 0;
            dp[i + 1][j + 1] += 0;
        }
        else
        {
            dp[i + 1][j - 1] += float((x - 1.0) / 2.0);
            dp[i + 1][j + 1] += float((x - 1.0) / 2.0);
        }
        if (vis[i + 1][j - 1] == false)
        {
            q.push({i + 1, j - 1});
            vis[i + 1][j - 1] = true;
        }
        if (vis[i + 1][j + 1] == false)
        {
            q.push({i + 1, j + 1});
            vis[i + 1][j + 1] = true;
        }
    }

    if (dp[n - 1][2 * m - 1] > 1)
        dp[n - 1][2 * m - 1] = 1.0;

    cout << fixed << setprecision(6) << dp[n - 1][2 * m - 1] << endl;
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