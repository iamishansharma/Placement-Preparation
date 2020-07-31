// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Functio to find first smallest positive
// missing number in the array
int missingNumber(int arr[], int n) 
{
    for(int i=0; i<n; i++)
        if(arr[i] < 1)
            arr[i] = n + 2;
            
    for(int i=0; i<n; i++)
    {
        int temp = abs(arr[i]);
        if(temp <= n)
        {
            int t2 = abs(arr[temp-1]);
            arr[temp-1] = (-1)*t2;
        }
    }
    
    for(int i=0; i<n; i++)
        if(arr[i] >= 0)
            return i+1;
            
    return n+1;
} 

// { Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)cin>>arr[i];
        cout<<missingNumber(arr, n)<<endl;
    }
    return 0; 
}   // } Driver Code Ends