// { Driver Code Starts
//Initial Template for C++


#include <iostream>
using namespace std;


 // } Driver Code Ends


//User function Template for C++

//Complete this function
int RecursivePower(int n, int p)
{
    if(p == 0)
        return 1;
    
    return n*RecursivePower(n,p-1);
}


// { Driver Code Starts.


int main() {
	int T;
	cin>>T;
	while(T--)
	{
	    int n,p;
	    cin>>n>>p;
	    cout<<RecursivePower(n,p)<<endl;
	}
	return 0;
}  // } Driver Code Ends