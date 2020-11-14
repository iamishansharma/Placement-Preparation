// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <fstream>
using namespace std;

// } Driver Code Ends

//User function Template for C++

//Complete this function
long long findNthFibonacci(int number, long long int dp[])
{
    if (dp[number] > 0)
        return dp[number];

    dp[number] = findNthFibonacci(number - 1, dp) + findNthFibonacci(number - 2, dp);
    return dp[number];
}

// { Driver Code Starts.
long long findNthFibonacci(int number, long long int dp[]);

int main()
{
    //initializing base value
    long long dp[100] = {0};
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;

    //taking total testcases
    int testcases;
    cin >> testcases;

    while (testcases--)
    {
        //taking nth number
        int number;
        cin >> number;

        //calling findNthFibonacci() function
        cout << findNthFibonacci(number, dp) << endl;
    }

    return 0;
}
// } Driver Code Ends