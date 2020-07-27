// { Driver Code Starts
//Initial Template for C++


// CPP program to generate power set
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function Template for C++

//Complete this function
void sub(vector<string> & ans, string s, string curr, int i)
{
    if(i == s.length())
    {
        ans.push_back(curr);
        return;
    }
    
    sub(ans, s, curr, i+1);
    sub(ans, s, curr + s[i], i+1);
}

vector <string> powerSet(string s)
{
   vector<string> ans;
   sub(ans, s, "", 0);
   sort(ans.begin(), ans.end());
   return ans;
}


// { Driver Code Starts.


// Driver code
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string s;
        cin>>s;
        vector<string> ans = powerSet(s);
        sort(ans.begin(),ans.end());
        for(auto x:ans)
        cout<<x<<" ";
        cout<<endl;
        
        
    }

return 0;
}   // } Driver Code Ends