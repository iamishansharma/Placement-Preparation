// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

int countWays(int);

// Driver program
int main()
{
    //taking number of testcases
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        cout << countWays(n) << endl;
    }
    return 0;
} // } Driver Code Ends

// function to count number of ways in which n can
// be written as sum of two or more than two integers
typedef long long int ll;
#define mod 1000000007

int countWays(int n)
{
    ll dp[n][n + 1];

    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (j == 0) // if we have no weight , choose empty subset
                dp[i][j] = 1;
            else if (i == 0) //if we have no items and still bag is not full
                dp[i][j] = 0;

            else if (i <= j) // we have 2 options either include or exclude
                dp[i][j] = (dp[i - 1][j] + dp[i][j - i]) % mod;
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return (dp[n - 1][n] % mod);
}