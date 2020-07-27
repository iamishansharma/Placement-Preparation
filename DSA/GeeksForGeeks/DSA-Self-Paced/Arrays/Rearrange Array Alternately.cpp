// { Driver Code Starts
// C++ program to rearrange an array in minimum 
// maximum form 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// This function wants you to modify the given input
// array and no need to return anything
// arr: input array
// n: size of array
void rearrange(long long *arr, int n) 
{ 
    int maxIndex = n-1, minIndex=0, maxTerm = arr[n-1] + 1;
    
	for(int i=0; i<n; i++)
	{
	    if(i%2 == 0)
	    {
	        arr[i] += (arr[maxIndex] % maxTerm) * maxTerm;
	        maxIndex--;
	    }
	    else
	    {
	        arr[i] += (arr[minIndex] % maxTerm) * maxTerm;
	        minIndex++;
	    }
	}
	
	for(int i=0; i<n; i++)
	    arr[i]=arr[i]/maxTerm;
}

// { Driver Code Starts.

// Driver program to test above function 
int main() 
{
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        
        long long arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        rearrange(arr, n);
        
        for (int i = 0; i < n; i++) 
		    cout << arr[i] << " ";
		
		cout << endl;
    }
	return 0; 
} 
  // } Driver Code Ends