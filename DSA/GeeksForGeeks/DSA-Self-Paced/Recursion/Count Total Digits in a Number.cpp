// { Driver Code Starts
//Initial Template for C++

#include <iostream>
using namespace std;


 // } Driver Code Ends


//User function Template for C++

//Complete this function
int countDigits(int n)
{
   if(n%10 == n || n == 0)
        return 1;
    
    return 1 + countDigits(n/10);
}

// { Driver Code Starts.

int main() {
	int T;
	cin>>T;
	while(T--)
	{
	    int n;
	    cin>>n;
	    
	    cout<<countDigits(n)<<endl;
	    
	    
	}
	return 0;
}


  // } Driver Code Ends