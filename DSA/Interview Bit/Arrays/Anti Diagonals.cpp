// https://www.interviewbit.com/problems/anti-diagonals/

vector<vector<int>> Solution::diagonal(vector<vector<int> > &A) 
{
    int n = A.size();
    int numb = n+n-1;
    
    vector<vector<int>> arr(numb,vector<int>(0));
    
    for(int y=0; y<n; y++)
        for(int x=0; x<n; x++)
                arr[x+y].push_back(A[y][x]);
                
    return arr;
}
