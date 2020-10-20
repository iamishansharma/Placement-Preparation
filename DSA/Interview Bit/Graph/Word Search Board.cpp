bool DFS(int i, int j, vector<string> &mat, string word, int currentIndex, int n, int m)
{
    if (currentIndex == word.size())
        return true;

    if (i < 0 || j < 0 || i >= n || j >= m || mat[i][j] != word[currentIndex])
        return false;

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    for (int p = 0; p < 4; p++)
    {
        int newx = i + dx[p];
        int newy = j + dy[p];

        if (DFS(newx, newy, mat, word, currentIndex + 1, n, m))
            return true;
    }

    return false;
}

int Solution::exist(vector<string> &mat, string word)
{
    int n = mat.size();

    if (n == 0)
        return (word.size() == 0);

    int m = mat[0].size();

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (DFS(i, j, mat, word, 0, n, m))
                return 1;

    return 0;
}
