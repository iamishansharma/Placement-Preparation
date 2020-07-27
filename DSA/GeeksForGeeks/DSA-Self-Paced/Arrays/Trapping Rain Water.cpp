// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends


   

// function to find the trapped water in between buildings
// arr: input array
// n: size of array
int trappingWater(int arr[], int n)
{
    int maxl[n];
    int maxr[n];
    
    maxl[0] = arr[0];
    maxr[n-1] = arr[n-1];
    
    for(int i=1; i<n; i++)
        maxl[i] = arr[i] > maxl[i-1] ? arr[i] : maxl[i-1];
    
    for(int i=n-2; i>=0; i--)
        maxr[i] = arr[i] > maxr[i+1] ? arr[i] : maxr[i+1];
        
    int water = 0;
    
    for(int i=1; i < n-1; i++)
        water += (min(maxl[i],maxr[i]) - arr[i]);
    
    return water;
}

// { Driver Code Starts.

int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        int n;
        
        cin >> n;
        
        int a[n];
        
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        
        cout << trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends