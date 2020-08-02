vector<int> Solution::nextPermutation(vector<int> &A) 
{
    int n = A.size();
    
    int i = n - 2, j = n - 1;
    
    while (i >= 0 && A[i] >= A[i + 1]) 
        i--;
        
    if (i != -1)
    {
        while (j >= 0 && A[i] >= A[j]) 
            j--;
            
        swap(A[i], A[j]);
    }     
    reverse(A.begin() + i + 1, A.end());
    return A;
}
