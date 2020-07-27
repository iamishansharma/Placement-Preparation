class Solution 
{
    public:
            int oddCells(int n, int m, vector<vector<int>>& indices) 
            {
                int result = 0;
                int mat[n][m];

                for(int i=0; i<n; i++)
                    for(int j=0;j<m;j++)
                        mat[i][j] = 0;

                for(int i=0; i<indices.size(); i++)
                    for(auto it=indices[i].begin(); it!=indices[i].end(); it+=2)
                    {
                        for(int j=0; j<m; j++)
                            mat[*it][j]+=1;
                        for(int k=0; k<n; k++)
                            mat[k][*(it+1)]+=1;
                    }

                for(int i=0; i<n; i++)
                    for(int j=0; j<m; j++)
                        if(mat[i][j]%2==1)
                            result++;

                return result;
            }
};