// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function Template for C++

//Complete this function
long long maximumSum(int arr[], int n)
{
    bool flag = true;
    int mini = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            flag = false;
            break;
        }
        mini = max(mini, arr[i]);
    }
    if (flag == true)
    {
        return mini;
    }

    int dp[n];
    dp[0] = max(0, arr[0]);
    dp[1] = max(dp[0], arr[1]);

    for (int i = 2; i < n; i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);

    return dp[n - 1];
}

// { Driver Code Starts.

int main()
{

    //taking total testcases
    int testcases;
    cin >> testcases;
    while (testcases--)
    {
        //taking size of array
        int sizeOfArray;
        cin >> sizeOfArray;

        int arr[sizeOfArray];

        //inserting elements in the array
        for (int i = 0; i < sizeOfArray; i++)
            cin >> arr[i];

        //calling function maximumSum()
        cout << maximumSum(arr, sizeOfArray) << endl;
    }
    return 0;
} // } Driver Code Ends