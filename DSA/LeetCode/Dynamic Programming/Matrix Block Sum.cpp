class Solution
{
public:
    int GetSum(int i, int j, vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();

        if (i < 0 || j < 0)
            return 0;
        if (i >= n)
            i = n - 1;
        if (j >= m)
            j = m - 1;

        return mat[i][j];
    }

    vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int K)
    {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> prefix(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                prefix[i][j] = mat[i][j] + GetSum(i - 1, j, prefix) + GetSum(i, j - 1, prefix) - GetSum(i - 1, j - 1, prefix);

        vector<vector<int>> ans(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans[i][j] = GetSum(i + K, j + K, prefix) - GetSum(i + K, j - K - 1, prefix) - GetSum(i - K - 1, j + K, prefix) + GetSum(i - K - 1, j - K - 1, prefix);
            }
        }

        return ans;
    }
};