// { Driver Code Starts
//Initial Template for C++

// CPP code to find largest and 
// second largest element in the array

#include <bits/stdc++.h>
using namespace std;

vector<int> largestAndSecondLargest(int, int[]);


 // } Driver Code Ends


     

/* Function to find largest and second largest element
*sizeOfArray : number of elements in the array
* arr = input array
*/
vector<int> largestAndSecondLargest(int n, int arr[])
{
    int max1 = INT_MIN, max2 = INT_MIN;
    
    /*********************************
     * Your code here
     * This function should return a
     * vector with first element as
     * max and second element as 
     * second max
     * *******************************/
    
    for(int i=0; i<n; i++)
        max1 = max(max1, arr[i]);
    
    for(int i=0; i<n; i++)
    {
        if(max1 == arr[i])
            continue;
        else
            max2 = max(max2, arr[i]);
    }
    
    max2 = (max2 == INT_MIN) ? -1 : max2;
    
    vector<int> ans;
    
    ans.push_back(max1);
    ans.push_back(max2);
    
    return ans;
}

// { Driver Code Starts.

// Driver Code
int main() {
	
	// Testcase input
	int testcases;
	cin >> testcases;
    
    // Looping through all testcases
	while(testcases--){
	    int sizeOfArray;
	    cin >> sizeOfArray;
	    
	    int arr[sizeOfArray];
	    
	    // Array input
	    for(int index = 0; index < sizeOfArray; index++){
	        cin >> arr[index];
	    }
	    
	    vector<int> ans = largestAndSecondLargest(sizeOfArray, arr);
	    cout<<ans[0]<<' '<<ans[1]<<endl;
	}
	
	return 0;
}  // } Driver Code Ends