// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find minimum adjacent difference
// arr[]: input array
// n: size of array
int minAdjDiff(int arr[], int n)
{    
    int minval = INT_MAX;
    
    for(int i=1; i<=n; i++)
        minval = min(minval, (abs(arr[i-1] - arr[i%n])));
        
    return minval;
}

// { Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin>>t; //Input testcases
    
    while(t--) //While testcases exist
    {
        int n;
        cin>>n; //Input size of array
        
        int arr[n]; //Array of size n
        
        for(int i = 0; i < n; i++)
        {
            cin>>arr[i]; //input elements of array
        }
        
        cout << minAdjDiff(arr, n) << endl;
    }
    return 0;
}  // } Driver Code Ends