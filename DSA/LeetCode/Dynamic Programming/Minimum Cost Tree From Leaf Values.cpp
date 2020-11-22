class Solution
{
public:
    int mctFromLeafValues(vector<int> &v)
    {
        int n = v.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int j = 0; j < n; j++)
        {
            for (int i = j; i > -1; i--)
            {
                for (int k = i; k < j; k++)
                {
                    int x = dp[i][k];
                    int y = dp[k + 1][j];

                    int t = x + y + *max_element(v.begin() + i, v.begin() + k + 1) * *max_element(v.begin() + k + 1, v.begin() + j + 1);

                    dp[i][j] = !dp[i][j] ? t : min(dp[i][j], t);
                }
            }
        }
        return dp[0][n - 1];
    }
};