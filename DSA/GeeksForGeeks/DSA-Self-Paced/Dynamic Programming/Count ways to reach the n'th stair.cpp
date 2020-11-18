// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

long long mod = 1000000007;

long long countWays(int);

int main()
{
    //taking total testcases
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
}
// } Driver Code Ends

// function to count ways to reach nth stair
long long countWays(int n)
{
    long long int dp[n + 1];

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;

    return dp[n] % 1000000007;
}
