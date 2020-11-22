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

    vector<vector<int>> mat(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
        mat[i][0] = 1;
    for (int i = 0; i < m; i++)
        mat[0][i] = 1;

    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            mat[i][j] = (mat[i - 1][j] + mat[i][j - 1]) % 1000000007;

    cout << mat[n - 1][m - 1] << endl;
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