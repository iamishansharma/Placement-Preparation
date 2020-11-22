class Solution
{
public:
    int dp[501][501];

    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        memset(dp, -1, sizeof dp);

        return solve(arr, 0, 0, k, arr[0]);
    }

    int solve(vector<int> &A, int i, int j, int k, int ele)
    {

        if (i - j > k)
            return INT_MIN;

        if (i == A.size())
            return ele * (i - j);

        if (dp[i][j] != -1)
            return dp[i][j];

        int opt_1 = solve(A, i + 1, j, k, max(A[i], ele));
        int opt_2 = ele * (i - j) + solve(A, i + 1, i, k, A[i]);

        return dp[i][j] = max(opt_1, opt_2);
    }
};