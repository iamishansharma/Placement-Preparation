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
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> mat(n, vector<int>(m, 0));

    for (int i = 0; i < k; i++)
    {
        int temp1;
        int temp2;

        cin >> temp1 >> temp2;

        mat[temp1 - 1][temp2 - 1] = -1;
    }

    mat[0][0] = 1;

    for (int i = 0; i < n; i++)
    {
        if (mat[i][0] == -1)
            break;
        else
            mat[i][0] = 1;
    }

    for (int i = 0; i < m; i++)
    {
        if (mat[0][i] == -1)
            break;
        else
            mat[0][i] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (mat[i][j] != -1)
            {
                int left = mat[i][j - 1];
                int up = mat[i - 1][j];

                mat[i][j] = ((left == -1 ? 0 : left) + (up == -1 ? 0 : up)) % mod;
            }
        }
    }

    // 	for(int i=0; i<n; i++)
    // 	{
    // 	    for(int j=0; j<m; j++)
    // 	    {
    // 	        cout<<mat[i][j]<<" ";
    // 	    }
    // 	    cout<<endl;
    // 	}

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