// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int dp[101][101];

int solve(int arr[], int i, int j)
{
    if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    return dp[i][j] = max(min(solve(arr, i + 1, j - 1) + arr[i], solve(arr, i + 2, j) + arr[i]), min(solve(arr, i + 1, j - 1) + arr[j], solve(arr, i, j - 2) + arr[j]));
}

long long maximumAmount(int arr[], int n)
{
    memset(dp, -1, sizeof(dp));

    return solve(arr, 0, n - 1);
}

// { Driver Code Starts.

int main()
{

    //taking total testcases
    int T;
    cin >> T;
    while (T--)
    {
        //taking number of elements
        int N;
        cin >> N;

        int A[N];

        //inserting the elements
        for (int i = 0; i < N; i++)
            cin >> A[i];

        //calling function maximumAmount()
        cout << maximumAmount(A, N) << endl;
    }
    return 0;
} // } Driver Code Ends