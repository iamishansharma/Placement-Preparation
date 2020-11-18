// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int longestSubsequence(int, int[]);

int main()
{
    //taking total testcases
    int t, n;
    cin >> t;
    while (t--)
    {
        //taking size of array
        cin >> n;
        int a[n];

        //inserting elements to the array
        for (int i = 0; i < n; i++)
            cin >> a[i];

        //calling method longestSubsequence()
        cout << longestSubsequence(n, a) << endl;
    }
}
// } Driver Code Ends

// return length of longest strictly increasing subsequence

/*int longestSubsequence(int n, int arr[])
{

    // DP O(n^2) -> 
    
    int dp[n];
    
    dp[0] = 1;
    
    int maxval = 1;
    
    for(int i=1; i<n; i++)
    {
        dp[i] = 1;
        
        for(int j=0; j<i; j++)
        {
            if(arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j]+1);
        }
        
        maxval = max(dp[i], maxval);
    }
    
    return maxval;
}*/

int ceilArr(int tail[], int l, int r, int x)
{
    while (l < r)
    {
        int m = l + (r - l) / 2;

        if (tail[m] >= x)
        {
            r = m;
        }
        else
        {
            l = m + 1;
        }
    }

    return r;
}

int longestSubsequence(int n, int arr[])
{
    int len = 1;

    int tail[n];
    tail[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > tail[len - 1])
        {
            tail[len] = arr[i];
            len++;
        }
        else
        {
            int c = ceilArr(tail, 0, len - 1, arr[i]);
            tail[c] = arr[i];
        }
    }
    return len;
}
