// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Functiuon to return number of trees

// Return the total number of BSTs possible with keys [1....N] inclusive.
int numTrees(int N)
{
    long long dp[N + 1];
    dp[0] = 1;

    for (int i = 1; i <= N; i++)
    {
        dp[i] = 0;

        for (int j = 0; j < i; j++)
        {
            long long sub_res = (dp[j] * dp[i - 1 - j]) % 1000000007;
            dp[i] = (dp[i] + sub_res) % 1000000007;
        }
    }

    return int(dp[N]);
}

// { Driver Code Starts.
#define mod (int)(1e9 + 7)
int main()
{

    //taking total testcases
    int t;
    cin >> t;
    while (t--)
    {

        //taking total number of elements
        int n;
        cin >> n;

        //calling function numTrees()
        cout << numTrees(n) << "\n";
    }
} // } Driver Code Ends