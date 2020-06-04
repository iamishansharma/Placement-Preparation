// https://www.interviewbit.com/problems/noble-integer/

int Solution::solve(vector<int> &A) 
{
    sort(A.begin(), A.end());
    int n = A.size();
    for(int i = 0; i < n; i++)
    {
        if(A[i] == n-i-1 && (i == n-1 || A[i] != A[i+1]))
            return(1);
    }
    return(-1);
}
