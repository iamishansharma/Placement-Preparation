// { Driver Code Starts
// Program to find best buying and selling days

#include <bits/stdc++.h>
using namespace std;
 
// solution structure
struct Interval
{
    int buy;
    int sell;
};



 // } Driver Code Ends


// solution structure
/* struct Interval
 {
     int buy;
     int sell;
 };*/

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int price[], int n)
{
    int minInd=0, maxInd=0, maxi = price[0], flag=0;
    
    for(int i=1; i<n; i++)
    {
        if(maxi < price[i])
            maxi = price[i];
        else if(maxi > price[i])
        {
            if(minInd!=maxInd)
            {
                flag=1;
                cout<<"("<<minInd<<" "<<maxInd<<") ";
            }
            minInd=i;
            maxi=price[i];
        }
        else if(price[minInd]==price[i])
            minInd=i;
        maxInd=i;
    }
    if(minInd!=maxInd)
    {
        flag=1;
        cout<<"("<<minInd<<" "<<maxInd<<")";
    }
    if(flag==0)
        cout<<"No Profit";
}

// { Driver Code Starts.
 
// Driver program to test above functions
int main()
{   
    
    int price[10000],n,i,T;
    
    scanf("%d",&T);
    
    while(T--){
        
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
      scanf("%d",&price[i]);
    // fucntion call
    stockBuySell(price, n);
    cout<<endl;
    }
    return 0;
}  // } Driver Code Ends