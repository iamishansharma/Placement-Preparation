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
    int n = 0;
    int m = 0;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];

    if (n == 1 || m == 1)
    {
        cout << "1" << endl;
        return;
    }

    int maxval = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (mat[i][j] == 1)
            {
                int minval = min(mat[i - 1][j - 1], min(mat[i - 1][j], mat[i][j - 1]));

                mat[i][j] = minval + 1;

                maxval = max(maxval, mat[i][j]);
            }
        }
    }

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