// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function Template for C++

//Complete this function
long long maximumSum(int arr[], int n)
{
    long long localmax = 0;
    long long maxval = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        localmax = max((long long int)arr[i], (long long int)arr[i] + localmax);
        cout << localmax << " ";
        maxval = max(maxval, localmax);
    }
    cout << endl;

    return maxval;
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

        //inserting elements to the array
        for (int i = 0; i < sizeOfArray; i++)
            cin >> arr[i];

        //calling function maximumSum()
        cout << maximumSum(arr, sizeOfArray) << endl;
    }
    return 0;
} // } Driver Code Ends