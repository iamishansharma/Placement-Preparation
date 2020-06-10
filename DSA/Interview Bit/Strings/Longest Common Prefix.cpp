// https://www.interviewbit.com/problems/longest-common-prefix/

string Solution::longestCommonPrefix(vector<string> &A) 
{
    string ans="";
    
    sort(A.begin(),A.end()); // o(n*logn)
    
    int n = A.size();
    string s = A[n-1];
    
    for(int j=0; j<A[0].size(); j++)
    {
        if(A[0][j] == A[n-1][j])
            ans += A[0][j];
        else
            break;
    }
    return ans;
}