class Solution 
{
    public:
            vector<int> luckyNumbers (vector<vector<int>>& matrix) 
            {
                vector<int>v;
                
                for(int i=0; i<matrix.size(); i++)
                {
                    vector<int>::iterator it;
                    
                    int min = *min_element(matrix[i].begin(),matrix[i].end());
                    it = find(matrix[i].begin(),matrix[i].end(),min);
                    int j = it - matrix[i].begin();
                    
                    int flag=0;
                    
                    for(int k=0; k<matrix.size(); k++)
                    {
                        if(matrix[k][j] > min)
                        {
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0)
                        v.push_back(min);
                }
                return v;
            }
};