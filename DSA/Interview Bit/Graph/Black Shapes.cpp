void DFS(int i, int j, vector<string> &mat, int n, int m)
{
    if (i < 0 || j < 0 || i == n || j == m || mat[i][j] != 'X')
        return;

    mat[i][j] = 'V';

    DFS(i + 1, j, mat, n, m);
    DFS(i - 1, j, mat, n, m);
    DFS(i, j + 1, mat, n, m);
    DFS(i, j - 1, mat, n, m);
}

int Solution::black(vector<string> &mat)
{
    int count = 0;

    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            if (mat[i][j] == 'X')
            {
                DFS(i, j, mat, mat.size(), mat[i].size());
                count++;
            }
        }
    }

    return count;
}
