// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
    int first;
    int second;
};



int maxChainLen(struct val p[],int n);
int main() {
    // your code goes here
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        val p[n];
        for(int i=0;i<n;i++)
        {
            cin>>p[i].first>>p[i].second;
        }
        
        cout<<maxChainLen(p,n)<<endl;
    }
    return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
    int first;
    int second;
};*/

/*You are required to complete this method*/
bool compare (struct val a,struct val b)
{
    if(a.first == b.first)
        return a.second < b.second;
    else
        return(a.first < b.first);
}
int maxChainLen(struct val a[],int n)
{
    int i;
    
    sort(a, a+n, compare);
    
    int lis[n];
    lis[0]=1;
    
    int j;
    
    for(i=1; i<(n); i++)
    {
        lis[i]=1;
        
        for(j=0; j<i; j++)
            if(a[i].first > a[j].second && lis[i] < 1+lis[j])
                lis[i]=lis[j]+1;
    }
    
    int mx = -1;
    
    for(i=0; i<n; i++)
    {
        if(lis[i] > mx)
            mx = lis[i];
    }
    
    return (mx);
}