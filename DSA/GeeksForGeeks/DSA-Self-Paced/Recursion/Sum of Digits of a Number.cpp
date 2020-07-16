// { Driver Code Starts
//Initial Template for C++



#include <iostream>
using namespace std;



 // } Driver Code Ends


//User function Template for C++

// Complete this function
int sumOfDigits(int n)
{
    if(n == 0)
        return 0;
        
    return n%10 + sumOfDigits(n/10);
}

// { Driver Code Starts.


int main() {
	int T;
	cin>>T;
	while(T--)
	{
	    int n;
	    cin>>n;
	    
	    cout<<sumOfDigits(n)<<endl;
	    
	    
	}
	return 0;
}  // } Driver Code Ends