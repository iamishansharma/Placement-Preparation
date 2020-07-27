// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 
void frequencycount(vector<int>& arr,int n);

 // } Driver Code Ends


void frequencycount(vector<int>& arr1,int n)
{ 
    for(int i=0; i<n; i++)
        arr1[i] -= 1;
    
    for(int i=0; i<n; i++)
        arr1[arr1[i]%n] += n;
        
    for(int i=0; i<n; i++)
        arr1[i] = arr1[i]/n;
}


// { Driver Code Starts.

int main() 
{ 
	long long t;
	cin >> t;
	
	while(t--){
	    
	    int n;
	    cin >> n; 
	    
	    vector<int> arr(n,0);
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr[i]; 
	    }

		frequencycount(arr,n); 
	    for (int i =0; i<n; i++) 
			cout<<arr[i]<<" ";
	    cout<<endl;
	}	
	return 0; 
}




  // } Driver Code Ends