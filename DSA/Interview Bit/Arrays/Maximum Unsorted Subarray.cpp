// https://www.interviewbit.com/problems/maximum-unsorted-subarray/

vector<int> Solution::subUnsort(vector<int> &A) 
{
    int n = A.size();
    
    int start = -1, end = -1;
    
    int maxi = A[0];
    
    for(int i = 1; i < n; i++)
    {
        if(A[i] < maxi) 
            end = i;
            
        maxi = max(maxi, A[i]);
    }
    
    if(end == -1) 
        return {-1}; // already sorted
        
    int mini = A[n-1];
    
    for(int i = n-1; i >= 0; i--)
    {
        if(A[i] > mini) 
            start = i;
            
        mini = min(mini, A[i]);
    }
    return {start, end};
}
