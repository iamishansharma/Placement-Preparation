int Solution::isMatch(const string A, const string B)
{
    int n = A.size();
    int m = B.size();

    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

    dp[0][0] = true;

    for (int i = 1; i <= m; i++)
    {
        dp[0][i] = false;

        if (i >= 2 && B[i - 1] == '*')
            dp[0][i] = dp[0][i - 2];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (A[i - 1] == B[j - 1] || B[j - 1] == '.')
                dp[i][j] = dp[i - 1][j - 1];
            else if (B[j - 1] == '*')
            {
                if (j >= 2 && (A[i - 1] == B[j - 2] || B[j - 2] == '.'))
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 2];
                else if (j >= 2)
                    dp[i][j] = dp[i][j - 2];
            }
            else
                dp[i][j] = false;
        }
    }

    return dp[n][m];
}
