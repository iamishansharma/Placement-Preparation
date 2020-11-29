class Solution
{
public:
    int Memo(int n, vector<int> &nums, int sum, vector<vector<int>> &dp)
    {
        if (sum == 0)
            return 1;

        if (n == 0)
            return 0;

        if (dp[n][sum] != -1)
            return dp[n][sum];

        if (nums[n] <= sum)
            dp[n][sum] = Memo(n - 1, nums, sum - nums[n], dp) || Memo(n - 1, nums, sum, dp);
        else
            dp[n][sum] = Memo(n - 1, nums, sum, dp);

        return dp[n][sum];
    }

    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
            sum += nums[i];

        if (sum % 2 != 0)
            return false;

        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        return Memo(n - 1, nums, sum / 2, dp);
    }
};