// { Driver Code Starts
// A Dynamic Programming based solution to compute nCr % p
#include <bits/stdc++.h>
using namespace std;

const int p = 1e9 + 7;

int nCrModp(int, int);

// Driver program
int main()
{
    int t, n, r;

    //taking count of testcases
    cin >> t;

    while (t--)
    {

        //taking n and r
        cin >> n >> r;

        //calling method nCrModp()
        cout << nCrModp(n, r) << endl;
    }

    return 0;
}
// } Driver Code Ends

// Returns nCr % p
int nCrModp(int n, int r)
{
    long long dp[n + 1][n + 1];

    if (r > n)
    {
        return 0;
    }

    dp[0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            dp[i][j] = 0;

            if (j >= 0 && j < i)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % p;
            }

            if (j - 1 >= 0 && j - 1 < i)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % p;
            }
        }
    }

    return dp[n][r];
}
