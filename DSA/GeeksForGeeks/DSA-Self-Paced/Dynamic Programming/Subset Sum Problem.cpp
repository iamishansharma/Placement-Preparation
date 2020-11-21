// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>

using namespace std;

bool findPartition(int *, int);

// Position this line where user code will be pasted.

int main()
{

    //taking total testcases
    int tc;
    cin >> tc;
    while (tc--)
    {

        //taking size of array
        int n, i;
        cin >> n;
        int a[n];

        //inserting elements in the array
        for (i = 0; i < n; i++)
            cin >> a[i];

        //calling findPartition() function and
        //printing "YES", if it returns true
        //else "NO"
        if (findPartition(a, n))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
// } Driver Code Ends

// User function template in C++

// a : given array
// n : size of the array

bool findPartition(int arr[], int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
        sum += arr[i];

    if (sum % 2 != 0)
        return false;
    else
    {
        int halfsum = sum / 2;

        bool dp[n + 1][halfsum + 1];

        for (int i = 0; i <= n; i++)
            dp[i][0] = true;
        for (int j = 0; j <= halfsum; j++)
            dp[0][j] = false;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= halfsum; j++)
            {
                if (arr[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[n][halfsum];
    }
}