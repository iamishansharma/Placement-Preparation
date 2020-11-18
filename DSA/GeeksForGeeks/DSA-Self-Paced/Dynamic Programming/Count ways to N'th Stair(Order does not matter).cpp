// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

long long mod = 1000000007;

long long countWays(int);

int main()
{
    //taking count of testcases
    int t;
    cin >> t;

    while (t--)
    {
        //taking stair count
        int m;
        cin >> m;

        cout << countWays(m) << endl; // Print the output from our pre computed array
    }
    return 0;
} // } Driver Code Ends

// function to count ways to reach mth stair
long long countWays(int m)
{
    long long dp[m + 1];

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for (long long i = 3; i <= m; i++)
        dp[i] = dp[i - 2] + 1;

    return dp[m];
}
