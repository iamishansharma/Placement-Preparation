// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

int minimumJumps(int[], int);

int main()
{
    //taking count of testcases
    int t;
    cin >> t;
    while (t--)
    {

        int n, i, j;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << minimumJumps(arr, n) << endl; // Function to calculate minimum number of jumps
    }
    return 0;
} // } Driver Code Ends

// function to find minimum number of jumps to reach end of the array
int minimumJumps(int arr[], int n)
{
    int jumps[n];

    for (int i = 1; i < n; i++)
        jumps[i] = INT_MAX;

    jumps[0] = 0;

    for (int i = 0; i < n; i++)
    {
        if (jumps[i] == INT_MAX)
            return -1;

        int temp = arr[i];
        int j = i + 1;

        while (temp--)
        {
            if (j < n)
                jumps[j] = min(jumps[j], 1 + jumps[i]);
            j++;
        }
    }
    return jumps[n - 1];
}
