// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function Template for C++

//Complete this function
long long numberOfWays(int coins[], int n, int sum)
{
    long long dp[sum + 1][n + 1];

    for (int j = 0; j <= n; j++)
        dp[0][j] = 1;

    for (int i = 1; i <= sum; i++)
        dp[i][0] = 0;

    for (int i = 1; i <= sum; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = dp[i][j - 1];

            if (coins[j - 1] <= i)
                dp[i][j] += dp[i - coins[j - 1]][j];
        }
    }

    return dp[sum][n];
}

// Space Optimised ->
long long numberOfWays(int coins[], int n, int sum)
{
    long long dp[sum + 1];

    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for (int i = 0; i < n; i++)
        for (int j = coins[i]; j <= sum; j++)
            dp[j] += dp[j - coins[i]];

    return dp[sum];
}

// { Driver Code Starts.

int main()
{

    //taking total count of testcases
    int testcases;
    cin >> testcases;
    while (testcases--)
    {
        //taking value
        int value;
        cin >> value;

        //taking number of coins
        int numberOfCoins;
        cin >> numberOfCoins;
        int coins[numberOfCoins];

        //inserting coins to the array
        for (int i = 0; i < numberOfCoins; i++)
            cin >> coins[i];

        //calling function numberOfWays
        cout << numberOfWays(coins, numberOfCoins, value) << endl;
    }
    return 0;
} // } Driver Code Ends