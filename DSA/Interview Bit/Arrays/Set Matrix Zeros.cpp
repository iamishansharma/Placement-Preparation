// https://www.interviewbit.com/problems/set-matrix-zeros/

void Solution::setZeroes(vector<vector<int>> &A) 
{
    long long int r = A.size(), c=A[0].size(), i, j;
    vector<int> row(r,false); //for storing the rows which contain at least one zero…
    vector<int> col(c,false); //for storing the columns which contain at least one zero…
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(A[i][j]==0)
            {
                row[i]=true; //ith row contains a zero…
                col[j]=true; //jth col contains a zero…
            }
        }
    }
    for(i=0;i<row.size();i++) // setting all the elements in respective rows with zero…
    {
        if(row[i])
            for(j=0;j<c;j++)
                A[i][j]=0;
    }
    for(i=0;i<col.size();i++) // setting all the elements in respective columns with zero…
    {
        if(col[i])
            for(j=0;j<r;j++)
                A[j][i]=0;
    }
}