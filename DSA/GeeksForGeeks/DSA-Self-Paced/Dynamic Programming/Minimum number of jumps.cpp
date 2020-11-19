// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int minimumJumps(int[], int);

int main()
{
    //taking count of testcases
    int t;
    cin>>t;
    while(t--)
    {
        
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
            
        cout<<minimumJumps(arr, n)<<endl;    // Function to calculate minimum number of jumps
    }
    return 0;
}// } Driver Code Ends


// function to find minimum number of jumps to reach end of the array
int minimumJumps(int arr[], int n)
{
    int dp[n];
    
    dp[0] = 0;
    
    for(int i=1; i<n; i++)
    {
        dp[i] = INT_MAX;
        
        for(int j=0; j<i; j++)
            if(arr[j] + j >= i)
                if(dp[j] != INT_MAX)
                    dp[i] = min(dp[i], dp[j] + 1);
    }
    
    return dp[n-1];
}
