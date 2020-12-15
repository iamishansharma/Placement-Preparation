// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


// User function Template for C++

class Solution{
public:
    int maximumPath(int n, vector<vector<int>> mat)
    {
        if(n == 1)
            return mat[0][0];
        
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(j == 0)
                    mat[i][j] += max(mat[i-1][j], mat[i-1][j+1]);
                else if(j == n-1)
                    mat[i][j] += max(mat[i-1][j], mat[i-1][j-1]);
                else
                    mat[i][j] += max(mat[i-1][j], max(mat[i-1][j+1], mat[i-1][j-1]));
            }
        }
        
        int maxval = 0;
        
        for(int i=0; i<n; i++)
            maxval = max(maxval, mat[n-1][i]);
        
        return maxval;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends