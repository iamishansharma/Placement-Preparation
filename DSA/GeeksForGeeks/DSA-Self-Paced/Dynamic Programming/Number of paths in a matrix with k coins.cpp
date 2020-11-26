#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 41
ll dp[M][M][M];
ll retret(int **a, int m, int n, int k)
{
    if (m < 0 || n < 0)
        return 0;
    if (k < 0)
        return 0;
    if (m == 0 && n == 0)
        return k == a[m][n];
    if (dp[m][n][k] != -1)
        return dp[m][n][k];
    return dp[m][n][k] = retret(a, m - 1, n, k - a[m][n]) + retret(a, m, n - 1, k - a[m][n]);
}
ll ret(int **a, int n, int k)
{
    memset(dp, -1, sizeof(dp));
    return retret(a, n - 1, n - 1, k);
}
int main()
{
    //code
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> k >> n;
        int **a = (int **)malloc(n * sizeof(int *));
        for (int i = 0; i < n; i++)
            a[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
            for (int i = 0; i < n; i++)
                cin >> a[i][j];
        cout << ret(a, n, k) << endl;
    }
    return 0;
}