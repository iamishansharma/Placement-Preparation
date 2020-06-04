// https://www.interviewbit.com/problems/rotate-matrix/

void Solution::rotate(vector<vector<int> > &A) 
{
    int n=A.size();
    
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(i>j) 
                swap(A[i][j],A[j][i]);
    
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(j<n/2) 
                swap(A[i][j],A[i][n-j-1]);
}
