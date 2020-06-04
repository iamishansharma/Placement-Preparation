// https://www.interviewbit.com/problems/first-missing-integer/

int Solution::firstMissingPositive(vector<int> &A) 
{
    int n = A.size();
    vector<int> present(n+1);
    
    for(int i=0; i<n; i++)
    {
        if(A[i] > 0 && A[i] <= n)
            present[A[i]] = 1;
    }
    
    for(int i=1; i<n+1; i++)
    {
        if(present[i] == 0)
            return i;
    }
    return n+1;
}
