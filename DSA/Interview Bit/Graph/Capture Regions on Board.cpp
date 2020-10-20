void DFS(int i, int j, vector<vector<char>> &mat)
{
    if (i < 0 || j < 0 || i == mat.size() || j == mat[0].size() || mat[i][j] != 'O')
        return;

    mat[i][j] = '*';

    DFS(i + 1, j, mat);
    DFS(i - 1, j, mat);
    DFS(i, j + 1, mat);
    DFS(i, j - 1, mat);
}

void Solution::solve(vector<vector<char>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();

    for (int i = 0; i < m; i++)
    {
        if (mat[0][i] == 'O')
            DFS(0, i, mat);
        if (mat[n - 1][i] == 'O')
            DFS(n - 1, i, mat);
    }

    for (int i = 0; i < n; i++)
    {
        if (mat[i][0] == 'O')
            DFS(i, 0, mat);
        if (mat[i][m - 1] == 'O')
            DFS(i, m - 1, mat);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 'O')
                mat[i][j] = 'X';
            if (mat[i][j] == '*')
                mat[i][j] = 'O';
        }
    }
}
