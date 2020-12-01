int LCS(string A, string B)
{
    int n = A.size();
    int m = B.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (A[i - 1] == B[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    //cout << dp[n][m] << endl;

    return dp[n][m];
}

int Solution::isInterleave(string A, string B, string C)
{
    if (LCS(A, C) == A.size() && LCS(B, C) == B.size() && C.size() <= (A.size() + B.size()))
        return 1;
    else
        return 0;
}
