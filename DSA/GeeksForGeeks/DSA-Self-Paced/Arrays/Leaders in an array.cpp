// { Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find the leaders in an array of size n
vector<int> leaders(int arr[], int n)
{
    int currmax = arr[n-1];
    
    vector<int> ans;
    
    ans.push_back(arr[n-1]);
    
    for(int i = n-2; i>=0; i--)
    {
        if(arr[i] >= currmax)
        {
            ans.push_back(arr[i]);
            currmax = arr[i];
        }
    }
    reverse(ans.begin(), ans.end());
    
    return ans;
}

// { Driver Code Starts.

int main()
{
   long long t;
   cin >> t;
   while (t--)
   {
       long long n;
       cin >> n;
        
        int a[n];
        
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        
        vector<int> v = leaders(a, n);
        
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        
        cout << endl;

   }
}
  // } Driver Code Ends