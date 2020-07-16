// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

void printNos(int N);
/* Driver program to test printNos */
int main()
{
    int T;
    cin>>T;
    
    while(T--)
    {
        int N;
        cin>>N;
        printNos(N);
        
        cout<<endl;
    }
    return 0;
}// } Driver Code Ends


//Complete this function
void printNos(int N)
{
    if(N == 0)
        return;
        
    printNos(N-1);
    
    cout<<N<<" ";
}