// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int max_sum(int A[],int N);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
        }

        cout<<max_sum(A,N)<<endl;
        /*keeping track of the total sum of the array*/

    }
}
// } Driver Code Ends


/*You are required to complete this method*/
int max_sum(int a[],int n)
{
    int sum=0,k=0,r,m;
    
    for(int i=0;i<n;i++)
        sum = sum + a[i];
        
    for(int i=0;i<n;i++)
        k = k + i*a[i];
    
    r = k;
    
    for(int i=0;i<n;i++)
    {
        m = k - sum + a[i]*n; 
        k = m;
        r = max(m,r);
    }
    return r;
}