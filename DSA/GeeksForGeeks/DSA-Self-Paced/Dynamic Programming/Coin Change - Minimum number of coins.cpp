// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Complete this function
long long minimumNumberOfCoins(int coins[], int numberOfCoins, int value)
{
    long long dp[value + 1];

    dp[0] = 0;

    for (int i = 1; i <= value; i++)
        dp[i] = INT_MAX;

    for (int i = 1; i <= value; i++)
        for (int j = 0; j < numberOfCoins; j++)
            if (coins[j] <= i)
                dp[i] = min(dp[i - coins[j]] + 1, dp[i]);

    return dp[value] == INT_MAX ? -1 : dp[value];
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

        //taking value of each coin
        for (int i = 0; i < numberOfCoins; i++)
            cin >> coins[i];

        //calling function minimumNumberOfCoins()
        int answer = minimumNumberOfCoins(coins, numberOfCoins, value);

        //printing "Not Possible" if answer is -1
        //else printing answer
        if (answer == -1)
            cout << "Not Possible" << endl;
        else
            cout << answer << endl;
    }
    return 0;
} // } Driver Code Ends