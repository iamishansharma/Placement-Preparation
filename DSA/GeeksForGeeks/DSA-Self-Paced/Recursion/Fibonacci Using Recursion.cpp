// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


//User function Template for C++

//Complete this function
long long fibonacci(int n)
{
    if(n == 0 || n == 1)
        return n;
        
    return fibonacci(n-1) + fibonacci(n-2);
}


// { Driver Code Starts.



int main() {
	int T;
	cin>>T;
	while (T--)
	{
	    int n;
	    cin>>n;
	    
	    cout<<fibonacci(n)<<endl;
	    
	    
	}
	return 0;
}  // } Driver Code Ends