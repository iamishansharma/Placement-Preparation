int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C)
{
    vector<pair<int, int>> V(B.size());

    for (int i = 0; i < B.size(); i++)
        V[i] = make_pair(B[i], C[i]);

    int maxCap = INT_MIN;

    for (int i = 0; i < A.size(); i++)
        maxCap = max(maxCap, A[i]);

    vector<vector<int>> dp(B.size() + 1, vector<int>(maxCap + 1, INT_MAX / 2));

    for (int i = 0; i < dp.size(); i++)
        dp[i][0] = 0;

    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 1; j < dp[0].size(); j++)
        {
            if (V[i - 1].first > j)
                dp[i][j] = dp[i - 1][j];
            else
            {
                int upper = j / V[i - 1].first;
                int minCost = dp[i - 1][j];

                for (int k = 0; k <= upper; k++)
                    minCost = min(minCost, (dp[i - 1][j - k * V[i - 1].first] + V[i - 1].second * k));

                dp[i][j] = min(minCost, dp[i - 1][j]);
            }
        }
    }

    int res = 0;

    for (int i = 0; i < A.size(); i++)
        res += dp[B.size()][A[i]];

    return res;
}
