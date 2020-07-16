// { Driver Code Starts
//Initial Template for C++


#include <iostream>
using namespace std;


 // } Driver Code Ends


//User function Template for C++

//Complete this function
int digitalRoot(int n)
{
    if(n < 10)
        return n;

    return digitalRoot(n%10 + n/10);
}

// { Driver Code Starts.


int main() {
	int T;
	cin>>T;
	while(T--)
	{
	    int n;
	    cin>>n;
	    
	    cout<<digitalRoot(n)<<endl;
	    
	    
	}
	return 0;
}  // } Driver Code Ends