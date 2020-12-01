int Solution::solve(const vector<int> &nums)
{
    int n = nums.size();

    int arraysum = 0;

    for (int i = 0; i < n; i++)
        arraysum += nums[i];

    int sum = arraysum / 2;

    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, INT_MAX));

    dp[0][0] = 0;

    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            int include = INT_MAX;

            if (nums[i - 1] <= j)
            {
                include = dp[i - 1][j - nums[i - 1]];

                if (include != INT_MAX)
                    include += 1;
            }
            dp[i][j] = min(include, dp[i - 1][j]);
        }
    }
    for (int i = sum; i >= 0; i--)
        if (dp[n][i] != INT_MAX)
            return dp[n][i];
}
