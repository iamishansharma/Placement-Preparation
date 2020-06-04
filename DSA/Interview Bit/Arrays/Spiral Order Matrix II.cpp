// https://www.interviewbit.com/problems/spiral-order-matrix-ii/

vector<vector<int>> Solution::generateMatrix(int n) 
{
    vector<vector<int>> res;
    
    if(n == 0)
        return res;

    vector<int> temp;
    
    for(int i = 0; i < n; i++)
        temp.push_back(0);
    for(int i = 0; i < n; i++)
        res.push_back(temp);
    
    int startRow = 0; 
    int endRow = n-1;
    int startCol = 0;
    int endCol = n-1;
    
    int val = 1;
    
    while(startRow <= endRow && startCol <= endCol)
    {
        for(int j = startCol; j<=endCol; j++)
        {
            res[startRow][j] = val;
            val++;
        }
        startRow++;
        for(int i = startRow; i <= endRow; i++)
        {
            res[i][endCol] = val;
            val++;
        }
        endCol--;
        for(int j = endCol; j>=startCol; j--)
        {
            res[endRow][j] = val;
            val++;
        }
        endRow--;
        for(int i = endRow; i>=startRow; i--)
        {
            res[i][startCol] = val;
            val++;
        }
        startCol++;
    }
    return res;
}