// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find circular subarray with maximum sum
// arr: input array
// num: size of array
int kadane(int a[], int n)
{
    int m=a[0],ans=a[0];
    
    for(int i=1; i<n; i++)
    {
        m = max(m + a[i],a[i]);
        ans = max(ans,m);
    }
    return ans;
}

int circularSubarraySum(int a[], int n)
{
    int x = kadane(a,n);
    
    if(x < 0)
        return x;
    
    int i,sum=0;
    
    for(i=0;i<n;i++)
    {
        sum += a[i];
        a[i] =- a[i];
    }
    int y=kadane(a,n);
    return max(x,y+sum);
}


// { Driver Code Starts.

int main()
 {
    int T;
    cin>> T;
    
    while (T--)
    {
        int num;
        cin>>num;
        int arr[num];
        for(int i = 0; i<num; i++)
            cin>>arr[i];
        
        
        cout << circularSubarraySum(arr, num) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends