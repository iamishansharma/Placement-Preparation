int helper(vector<vector<int>> &dp, int i, int j, const string A, const string B)
{
    if (dp[i][j] == -1)
    {
        if (j == 0)
            dp[i][j] = 1;

        else if (i == 0)
            dp[i][j] = 0;
        else
            dp[i][j] = (A[i - 1] == B[j - 1] ? helper(dp, i - 1, j - 1, A, B) : 0) + helper(dp, i - 1, j, A, B);
    }
    return dp[i][j];
}

int Solution::numDistinct(string A, string B)
{

    int n = A.size(), m = B.size();

    if (n < m)
        return 0;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return helper(dp, n, m, A, B);
}
