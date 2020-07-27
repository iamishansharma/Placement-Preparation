// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find subarray with maximum sum
// arr: input array
// n: size of array
int maxSubarraySum(int arr[], int n)
{
    for(int i=1; i<n; i++)
        arr[i] = max(arr[i], arr[i] + arr[i-1]);
    
    int maxval = INT_MIN;
    
    for(int i=0; i<n; i++)
        maxval = max(maxval, arr[i]);
    
    return maxval;
}

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
        
        cout << maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends