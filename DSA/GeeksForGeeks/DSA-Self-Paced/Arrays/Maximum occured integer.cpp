// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;




 // } Driver Code Ends


// L and R are input array
// maxx : maximum in R[]
// n: size of array
// arr[] : declared globally with size equal to maximum in L[] and R[]

int maxOccured(int L[], int R[], int n, int maxx)
{
    int arr[maxx] = {0};
    
    for(int i = 0; i < n; i++)
    {
        arr[L[i]] += 1;
        arr[R[i]+1] -= 1;
    }
    
    int maxi = arr[0], res = 0;
    for(int i = 1; i < maxx; i++)
    {
        arr[i] += arr[i-1];
        
        if(maxi < arr[i])
        {
            maxi = arr[i];
            res = i;
        }
    }
    
    return res;
}

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    int n;
	    cin >> n;
	    int L[n];
	    int R[n];
	    for(int i = 0;i<n;i++){
	        cin >> L[i];
	    }
	    
	    int maxx = 0;
	    for(int i = 0;i<n;i++){
	        
	        cin >> R[i];
	        if(R[i] > maxx){
	            maxx = R[i];
	        }
	    }
	    
	    cout << maxOccured(L, R, n, maxx) << endl;
	}
	
	return 0;
}  // } Driver Code Ends