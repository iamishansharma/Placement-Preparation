// { Driver Code Starts
//Initial Template for C++


#include<iostream> 
using namespace std; 


 // } Driver Code Ends


//User function Template for C++

//Complete this function
#include <bits/stdc++.h>
int maxEvenOdd(int arr[],int n)
{
    vector<int> vect;
    int cnt=0;
    int f;
    if(arr[0]%2==0)
    {
        f=0;
        cnt++;
    }
    else
    {
        f=1;
        cnt++;
    }
    for(int i=1;i<n;i++)
    {
        if(f==0)
        {
            if(arr[i]%2!=0)
            {
                cnt++;
                f=1;
            }
            else
            {
                vect.push_back(cnt);
                cnt=0;
            }
        }
        else if(f==1)
        {
            if(arr[i]%2==0)
            {
                cnt++;
                f=0;
            }
            else
            {
                vect.push_back(cnt);
                cnt=0;
            }
        }
        if(cnt==0)
        {
            if(arr[i]%2==0)
            {
                f=0;
                cnt++;
            }
            else
            {
                f=1;
                cnt++;
            }
        }
    }
    vect.push_back(cnt);
    int ret=INT_MIN;
    for(auto it=vect.begin();it!=vect.end();it++)
    {
        if(ret<*(it))
                ret=*(it);
    }
    return ret;
}

// { Driver Code Starts.



/* Driver program to test maxSubArraySum */
int main() 
{ 
    int testcases;
    cin>>testcases;
    while(testcases--)
    {
        int sizeOfArray;
        cin>>sizeOfArray;
        int arr[sizeOfArray];
        
        for(int i=0;i<sizeOfArray;i++)
        {
            cin>>arr[i];
        }
        cout  << maxEvenOdd(arr, sizeOfArray)<<endl; 
    }
   return 0; 
} 
  // } Driver Code Ends