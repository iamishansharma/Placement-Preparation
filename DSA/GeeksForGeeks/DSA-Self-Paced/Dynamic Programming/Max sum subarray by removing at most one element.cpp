// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int maxSumSubarray(int[], int);

int main()
{
    // your code goes here

    //taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        //taking total elements
        int n;
        cin >> n;
        int a[n];

        //inserting elements in the array
        for (int i = 0; i < n; i++)
            cin >> a[i];

        //calling method maxSumSubarray()
        cout << maxSumSubarray(a, n) << endl;
    }
}

// } Driver Code Ends

/*You are required to complete below method */
int maxSumSubarray(int A[], int n)
{
    int fwsum[n], bwsum[n];

    fwsum[0] = A[0];
    int maxSumWithoutSkipping = INT_MIN;

    if (fwsum[0] > maxSumWithoutSkipping)
        maxSumWithoutSkipping = fwsum[0];

    for (int i = 1; i < n; i++)
    {
        fwsum[i] = max(A[i], fwsum[i - 1] + A[i]);

        if (maxSumWithoutSkipping < fwsum[i])
            maxSumWithoutSkipping = fwsum[i];
    }

    bwsum[n - 1] = A[n - 1];

    for (int i = n - 2; i >= 0; i--)
        bwsum[i] = max(A[i], bwsum[i + 1] + A[i]);

    int maxsum = INT_MIN;

    for (int i = 1; i <= n - 2; i++)
    {
        int maxat = max(A[i], fwsum[i - 1] + bwsum[i + 1]);

        if (maxat > maxsum)
            maxsum = maxat;
    }
    return max(maxsum, maxSumWithoutSkipping);
}