class Solution 
{
    public:
            vector<vector<int>> flipAndInvertImage(vector<vector<int>>& grid) 
            {
                int temp = 0;
                
                for(int i=0; i<grid.size(); i++)
                {
                    for(int j=0; j < grid[i].size()/2; j++)
                    {
                        temp = grid[i][grid[i].size()-1-j];
                        grid[i][grid[i].size()-1-j] = grid[i][j];
                        grid[i][j] = temp;
                    }
                }
                
                for(int i=0; i<grid.size(); i++)
                    for(int j=0; j<grid[i].size(); j++)
                        grid[i][j] = grid[i][j] == 1 ? 0 : 1;
            
                return grid;
            }
};